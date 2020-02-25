/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 23:59:37 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/25 16:37:19 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_player(t_game *game)
{
	t_point iter;

	iter = point(-1, -1);
	while (++(iter.x) < 7)
	{
		iter.y = -1;
		while (++(iter.y) < 7)
			image_set_pixel(&(game->img), game->map.res[0] - 10 - MINIMAP_SIZE
			/ 2 + iter.x - 3, 10 + MINIMAP_SIZE / 2 + iter.y - 3, 0xFF0000);
	}
	iter = point(-1, -30);
	while (++(iter.y) < 30)
	{
		iter.x = -1;
		while (++(iter.x) < 17)
			image_set_pixel(&(game->img), game->map.res[0] - 10 - MINIMAP_SIZE
			/ 2 + iter.x * cos(to_radians(game->p.cam_angle + iter.y - 180)),
			10 + MINIMAP_SIZE / 2 + iter.x * sin(to_radians(game->p.cam_angle
			+ iter.y - 180)), 0xBBBBBB);
	}
}

static void	draw_map_at(t_point iter, t_game *game, int wall_size)
{
	t_point coords;
	char	tile;

	coords = point(game->p.pos.x - ((iter.x - MINIMAP_SIZE / 2) *
			CUBE_SIZE / wall_size), game->p.pos.y + ((iter.y -
			MINIMAP_SIZE / 2) * CUBE_SIZE / wall_size));
	if ((tile = get_tile_at(coords, game->map.map_d)) == '1' ||
		tile == -1)
		image_set_pixel(&(game->img), game->map.res[0] - 10
						- iter.x, 10 + iter.y, 0xFFFFFF);
	else if (tile == '2' && (int)coords.x % CUBE_SIZE > CUBE_SIZE
		* 0.4 && (int)coords.x % CUBE_SIZE < CUBE_SIZE * 0.6
		&& (int)coords.y % CUBE_SIZE > CUBE_SIZE * 0.4 &&
		(int)coords.y % CUBE_SIZE < CUBE_SIZE * 0.6)
		image_set_pixel(&(game->img), game->map.res[0] - 10 -
		iter.x, 10 + iter.y, 0xFFFF00);
	else
		image_set_pixel(&(game->img), game->map.res[0] - 10 -
		iter.x, 10 + iter.y, 0x000000);
}

void		render_minimap(t_game *game)
{
	t_point iter;
	int		wall_size;

	wall_size = MINIMAP_SIZE / 11;
	iter = point(-1, -1);
	while (++(iter.x) < MINIMAP_SIZE)
	{
		iter.y = -1;
		while (++(iter.y) < MINIMAP_SIZE)
			draw_map_at(iter, game, wall_size);
	}
	render_player(game);
}
