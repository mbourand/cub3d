/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:16:14 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/08 20:36:46 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_player *p, t_map map)
{
	t_point		pos;
	int			i;

	i = 0;
	while (++i < MOVE_SPEED)
	{
		pos.x = p->pos.x + i * cos(to_radians(p->cam_angle));
		pos.y = p->pos.y + i * sin(to_radians(p->cam_angle));
		if (get_tile_at(pos, map.map_d) == '1')
		{
			pos.x = p->pos.x + (i - PLAYER_SIZE) * cos(to_radians(p->cam_angle));
			pos.y = p->pos.y + (i - PLAYER_SIZE) * sin(to_radians(p->cam_angle));
			break ;
		}
	}
	p->pos.x = pos.x;
	p->pos.y = pos.y;
}

int	key_pressed(int key, void *param)
{
	t_player	*player;
	t_game		*game;

	game = (t_game*)param;
	player = (t_player*)&(game->p);
	if (key == K_CAMLEFT)
		player->cam_angle = constrain(player->cam_angle - CAM_SPEED, 0, 360);
	if (key == K_CAMRIGHT)
		player->cam_angle = constrain(player->cam_angle + CAM_SPEED, 0, 360);
	if (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT)
	{
		player->cam_angle += get_angle(key);
		move_player(player, game->map);
		player->cam_angle -= get_angle(key);
	}
	render(game);
	return (0);
}
