#include "cub3d.h"

void	move_player(t_player *p, t_map map, int key)
{
	t_point		pos;
	int			i;

	i = 0;
	p->cam_angle += get_angle(key);
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
	p->cam_angle -= get_angle(key);
	p->pos.x = pos.x;
	p->pos.y = pos.y;
}

int		keys_actions(int key, t_game *game)
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
		move_player(&(game->p), game->map, key);
	else
		return (0);
	return (1);
}

int		actions(void *param)
{
	int		i;
	int		rend;
	t_game	*game;

	game = (t_game*)param;
	i = -1;
	rend = 8;
	while (++i < 8)
	{
		if (!keys_actions(game->keys[i], game))
			rend--;
		if (game->floor_coef >= game->map.res[1] / 2)
			game->floor_coef = game->map.res[1] / 2 - 1;
		if (game->floor_coef <= -game->map.res[1] / 2)
			game->floor_coef = -game->map.res[1] / 2 + 1;
	}
	if (rend)
		render(game, 0);
	return (0);
}