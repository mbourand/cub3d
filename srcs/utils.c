/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:45 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/25 16:53:21 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			rgbtoint(int rgb[3])
{
	int color;

	if (rgb[0] > 255 || rgb[0] < 0 || rgb[1] > 255 || rgb[1] < 0 ||
			rgb[2] > 255 || rgb[2] < 0)
		return (-1);
	color = (rgb[0] << 16);
	color += (rgb[1] << 8);
	color += rgb[2];
	return (color);
}

void		reset_map(t_map *map)
{
	map->res[0] = -1;
	map->res[1] = -1;
	ft_strdel(&(map->tex_no));
	ft_strdel(&(map->tex_so));
	ft_strdel(&(map->tex_we));
	ft_strdel(&(map->tex_ea));
	ft_strdel(&(map->tex_s));
	map->col_f = -1;
	map->col_c = -1;
	if (map->map_d)
		ft_lstclear(&(map->map_d), &free);
}

void		init_game(t_game *game)
{
	int i;

	(game->map.res)[0] = -1;
	(game->map.res)[1] = -1;
	game->map.tex_no = 0;
	game->map.tex_so = 0;
	game->map.tex_we = 0;
	game->map.tex_ea = 0;
	game->map.tex_s = 0;
	game->map.col_c = -1;
	game->map.col_f = -1;
	game->map.map_d = 0;
	game->floor_coef = 0;
	game->spritecoords = 0;
	game->p.pos.x = CUBE_SIZE + CUBE_SIZE / 2.0;
	game->p.pos.y = CUBE_SIZE + CUBE_SIZE / 2.0;
	game->p.cam_angle = 0;
	i = -1;
	while (++i < 8)
		game->keys[i] = -1;
}

void		error(char *message)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void		quit(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}
