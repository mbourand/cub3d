/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:04:20 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/25 16:36:37 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	find_wall(t_point step, t_point *intersect, t_game *game)
{
	int found;

	found = 0;
	while (found != '1')
	{
		if ((found = get_tile_at(*intersect, game->map.map_d)) == -1)
			return (-1);
		if (found == '1')
			return (distance(game->p.pos, *intersect));
		intersect->x += step.x;
		intersect->y += step.y;
	}
	return (-1);
}

static double	set_ray(t_ray *ray, double distance, double wall)
{
	ray->distance = distance;
	ray->wall = wall;
	return (distance);
}

static void		cast_horizontal(t_game *game, t_ray *ray, double *distance,
	double *wall)
{
	t_point		inter;
	t_point		step;

	inter.y = (int)floor(game->p.pos.y / CUBE_SIZE) * CUBE_SIZE +
		(ray->angle < 180 ? -0.001 : CUBE_SIZE);
	inter.x = game->p.pos.x + ((game->p.pos.y - inter.y) * -1) /
		tan(to_radians(ray->angle));
	step.y = (ray->angle < 180 ? -CUBE_SIZE : CUBE_SIZE);
	step.x = step.y / tan(to_radians(ray->angle));
	*distance = find_wall(step, &inter, game);
	*wall = (int)(inter.x) % CUBE_SIZE;
}

static void		cast_vertical(t_game *game, t_ray *ray, double *distance,
	double *wall)
{
	t_point		inter;
	t_point		step;

	inter.x = floor(game->p.pos.x / CUBE_SIZE) * CUBE_SIZE +
		(ray->angle < 270 && ray->angle > 90 ? CUBE_SIZE : -0.001);
	inter.y = game->p.pos.y + ((game->p.pos.x - inter.x) * -1) *
		tan(to_radians(ray->angle));
	step.x = (ray->angle < 270 && ray->angle > 90 ? CUBE_SIZE : -CUBE_SIZE);
	step.y = step.x * tan(to_radians(ray->angle));
	*distance = find_wall(step, &inter, game);
	*wall = (int)(inter.y) % CUBE_SIZE;
}

double			cast(t_game *game, t_ray *ray)
{
	t_point distance;
	t_point wall;

	ray->wall = -1;
	ray->distance = -1;
	if (ray->angle != 0)
		cast_horizontal(game, ray, &(distance.x), &(wall.x));
	cast_vertical(game, ray, &(distance.y), &(wall.y));
	if ((distance.x == -1 && distance.y != -1) ||
		(distance.y != -1 && distance.y <= distance.x))
	{
		ray->face = (ray->angle < 270 && ray->angle > 90 ? FACE_EAST :
				FACE_WEST);
		return (set_ray(ray, distance.y, wall.y));
	}
	if ((distance.y == -1 && distance.x != -1) ||
		(distance.x != -1 && distance.x < distance.y))
	{
		ray->face = (ray->angle < 180 ? FACE_NORTH : FACE_SOUTH);
		return (set_ray(ray, distance.x, wall.x));
	}
	return (ray->distance = -1);
}
