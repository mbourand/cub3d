/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:20:04 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/26 13:20:55 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		sprite_collision(t_game *game)
{
	int		i;
	int		size;
	t_point *pt;

	size = ft_lstsize(game->spritecoords);
	i = -1;
	while (++i < size)
	{
		pt = (t_point*)ft_lstat(game->spritecoords, i)->content;
		if (get_tile_at_grid(*pt, game->map.map_d) != '2')
			continue ;
		if (distance(game->p.pos, point(pt->x * CUBE_SIZE + CUBE_SIZE / 2,
						pt->y * CUBE_SIZE + CUBE_SIZE / 2)) < CUBE_SIZE)
		{
			set_tile_at_grid(*pt, '0', game->map.map_d);
		}
	}
}

void		move_player(t_game *game, int key, double speed)
{
	t_point		pos;
	int			i;

	i = 0;
	game->p.cam_angle += get_angle(key);
	while (++i < speed)
	{
		pos.x = game->p.pos.x + i * cos(to_radians(game->p.cam_angle));
		pos.y = game->p.pos.y + i * sin(to_radians(game->p.cam_angle));
		if (get_tile_at(pos, game->map.map_d) == '1')
		{
			pos.x = game->p.pos.x + (i - PLAYER_SIZE)
				* cos(to_radians(game->p.cam_angle));
			pos.y = game->p.pos.y + (i - PLAYER_SIZE)
				* sin(to_radians(game->p.cam_angle));
			break ;
		}
	}
	game->p.cam_angle -= get_angle(key);
	game->p.pos.x = pos.x;
	game->p.pos.y = pos.y;
	sprite_collision(game);
}

int			keys_actions(int key, t_game *game)
{
	if (key == K_CAMLEFT)
		game->p.cam_angle = constrain(game->p.cam_angle - CAM_SPEED, 0, 360);
	else if (key == K_CAMRIGHT)
		game->p.cam_angle = constrain(game->p.cam_angle + CAM_SPEED, 0, 360);
	else if (key == K_CAMUP)
		game->floor_coef -= CAM_SPEED_V;
	else if (key == K_CAMDOWN)
		game->floor_coef += CAM_SPEED_V;
	else if (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT)
		move_player(game, key
			, 0 + MOVE_SPEED * (key == K_RIGHT || key == K_LEFT ? 0.75 : 1));
	else if (key == K_SCREENSHOT)
		return (8);
	else
		return (1);
	return (0);
}

int			actions(void *param)
{
	int		i;
	int		rend;
	t_game	*game;

	game = (t_game*)param;
	i = -1;
	rend = 8;
	while (++i < 8)
	{
		rend -= keys_actions(game->keys[i], game);
		if (game->floor_coef >= game->map.res[1] / 2)
			game->floor_coef = game->map.res[1] / 2 - 1;
		if (game->floor_coef <= -game->map.res[1] / 2)
			game->floor_coef = -game->map.res[1] / 2 + 1;
	}
	if (rend)
		render(game, 0);
	return (0);
}
