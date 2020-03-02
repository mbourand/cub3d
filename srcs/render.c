/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:33:59 by mbourand          #+#    #+#             */
/*   Updated: 2020/03/02 16:46:33 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			render(t_game *game, int save)
{
	double	angle_offset;
	int		i;

	angle_offset = (FOV / (double)((game->map.res)[0]));
	i = 0;
	while (i < game->map.res[0])
	{
		game->p.rays[i].angle = constrain(game->p.cam_angle +
				((i - game->map.res[0] / 2) * angle_offset), 0, 360);
		cast(game, &(game->p.rays[i]));
		if (game->p.rays[i].distance != -1)
			render_wall(game, &(game->p.rays[i]), i);
		i++;
	}
	render_sprites(game);
	render_hud(game);
	if (save)
		save_image(game->img);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->img.img);
	game->img.img = mlx_new_image(game->mlx_ptr, game->map.res[0],
			game->map.res[1]);
	game->img.data = mlx_get_data_addr(game->img.img, &(game->img.bpp),
			&(game->img.size_line), &(game->img.endian));
	return (0);
}
