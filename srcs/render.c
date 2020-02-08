/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:33:59 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/08 20:30:01 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	render_background(t_game *game, int x)
{
	int j;
	
	j = -1;
	while (++j < game->map.res[1])
		image_set_pixel(&(game->img), x, j, (j < game->map.res[1] / 2 ? game->map.col_c : game->map.col_f));
}

int			render(t_game *game)
{
	double	angle_offset;
	int		i;

	angle_offset = (FOV / (double)((game->map.res)[0]));
	i = 0;
	while (i < game->map.res[0])
	{
		game->p.ray.angle = constrain(game->p.cam_angle + ((i - game->map.res[0] / 2) * angle_offset), 0, 360);
		cast(game, &(game->p.ray));
		if (game->p.ray.distance != -1)
		{
			render_background(game, i);
			render_wall(game, i);
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->img.img);
	game->img.img = mlx_new_image(game->mlx_ptr, game->map.res[0], game->map.res[1]);
	game->img.data = mlx_get_data_addr(game->img.img, &(game->img.bpp), &(game->img.size_line), &(game->img.endian));
	return (0);
}
