/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:45 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/10 21:21:06 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_list		*point_lstnew(double x, double y)
{
	t_point	*point;
	t_list	*elem;

	if (!(point = malloc(sizeof(t_point))))
		error("An allocation error has occured.");
	point->x = x;
	point->y = y;
	if (!(elem = ft_lstnew(point)))
		error("An allocation error has occured.");
	return (elem);
}