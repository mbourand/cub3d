/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:18:03 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/10 03:55:12 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		load_image(char *file, t_image *img, void *mlx_ptr)
{
	if (!(img->img = mlx_xpm_file_to_image(mlx_ptr, file, &(img->w),
					&(img->h))))
		return (0);
	if (!(img->data = mlx_get_data_addr(img->img, &(img->bpp),
					&(img->size_line), &(img->endian))))
		return (0);
	return (1);
}

t_image	get_texture_face(t_game *game, int face)
{
	t_image textures[4] = {game->tex_no, game->tex_so, game->tex_we, game->tex_ea};

	if (face < 0 || face > 3)
		return (game->tex_no);
	return (textures[face]);
}

void	image_set_pixel(t_image *img, int x, int y, int color)
{
	if (!ft_inrange(x, 0, img->w) || !ft_inrange(y, 0, img->h))
		return ;
	*(int*)(img->data + ((x + (y * img->w)) * (img->bpp / 8))) = color;
}

int		image_get_color(t_image img, int x, int y)
{
	if (!ft_inrange(x, 0, img.w) || !ft_inrange(y, 0, img.h))
		return (0);
	return (*(int*)(img.data + ((x + (y * img.w)) * (img.bpp / 8))));
}