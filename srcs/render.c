/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:33:59 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/11 17:36:43 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	render_background(t_game *game, int x)
{
	int j;
	
	j = -1;
	while (++j < game->map.res[1])
		image_set_pixel(&(game->img), x, j, (j < game->map.res[1] / 2 - game->floor_coef ? game->map.col_c : game->map.col_f));
}

static void	write_int(unsigned char *str, int value)
{
	str[0] = (unsigned char)(value);
	str[1] = (unsigned char)(value >> 8);
	str[2] = (unsigned char)(value >> 16);
	str[3] = (unsigned char)(value >> 24);
}

static int	write_header(int fd, int size, t_game *game)
{
	int				index;
	unsigned char	header[54];

	index = 0;
	while (index < 54)
		header[index++] = (unsigned char)(0);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	write_int(header + 2, size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	write_int(header + 18, game->map.res[0]);
	write_int(header + 22, game->map.res[1]);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, 54) < 0));
}

static int		write_data(int file, t_game *game)
{
	t_point	pos;
	int		color;

	pos.y = game->map.res[1];
	while (pos.y > 0)
	{
		pos.x = 0;
		while (pos.x < game->map.res[0])
		{
			color = image_get_color(game->img, pos.x, pos.y);
			if (write(file, &color, 3) < 0)
				return (0);
			pos.x++;
		}
		pos.y--;
	}
	return (1);
}

static void	save_image(t_game *game)
{
	int fd;

	if (!(fd = open("screenshot.bmp", O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR | S_IROTH | S_IRGRP)))
		error(ERR_SCREEN_OPEN);
	if (!write_header(fd, 54 + ((int)game->map.res[0] * (int)game->map.res[1]), game))
		error(ERR_SCREEN_WRITE);
	if (!write_data(fd, game))
		error(ERR_SCREEN_WRITE);
	close(fd);
}

int			render(t_game *game, int save)
{
	double	angle_offset;
	int		i;

	angle_offset = (FOV / (double)((game->map.res)[0]));
	i = 0;
	while (i < game->map.res[0])
	{
		game->p.rays[i].angle = constrain(game->p.cam_angle + ((i - game->map.res[0] / 2) * angle_offset), 0, 360);
		cast(game, &(game->p.rays[i]));
		render_background(game, i);
		if (game->p.rays[i].distance != -1)
			render_wall(game, &(game->p.rays[i]), i);
		i++;
	}
	render_sprites(game);
	if (save)
		save_image(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->img.img);
	game->img.img = mlx_new_image(game->mlx_ptr, game->map.res[0], game->map.res[1]);
	game->img.data = mlx_get_data_addr(game->img.img, &(game->img.bpp), &(game->img.size_line), &(game->img.endian));
	return (0);
}
