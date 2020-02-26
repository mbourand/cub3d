/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:56:53 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/26 13:19:26 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point			*ft_lsttotab(t_list *list)
{
	t_point *res;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(list);
	if (!(res = malloc(sizeof(t_point) * size)))
		error(ERR_ALLOCATION);
	while (i < size)
	{
		res[i] = *(t_point*)(list->content);
		list = list->next;
		i++;
	}
	return (res);
}

t_point			*sort_sprites(t_point *sprites, int size, t_point pos)
{
	int j;

	j = -1;
	while (++j < size - 1)
	{
		if (distance(pos, point(sprites[j + 1].x * CUBE_SIZE + CUBE_SIZE / 2,
								sprites[j + 1].y * CUBE_SIZE + CUBE_SIZE / 2)) >
			distance(pos, point(sprites[j].x * CUBE_SIZE + CUBE_SIZE / 2,
								sprites[j].y * CUBE_SIZE + CUBE_SIZE / 2)))
		{
			swap(&(sprites[j + 1]), &(sprites[j]));
			j = -1;
		}
	}
	return (sprites);
}

void			draw_col(t_game *game, t_point sdata, t_point iter, int x_mid)
{
	t_point	tex;
	int		color;
	double	size;

	size = sdata.x;
	if (size < game->map.res[1] || game->floor_coef - game->map.res[1] / 2 < 0)
		iter.y = -1;
	else
		iter.y = size / 2 + game->floor_coef - game->map.res[1] / 2 - 1;
	while (++(iter.y) < size && game->map.res[1] / 2 - game->floor_coef +
			iter.y - (size / 2) < game->map.res[1])
	{
		tex = point((iter.x + size / 2) / size * game->tex_s.w,
				iter.y / size * game->tex_s.h);
		if (x_mid + iter.x < 0 || x_mid + iter.x >= game->map.res[0] ||
				game->map.res[1] / 2 - game->floor_coef + iter.y -
				(size / 2) >= game->map.res[1])
			break ;
		if ((color = image_get_color(game->tex_s, tex.x, tex.y)) ==
	TRANSPARENT_COLOR || game->p.rays[(int)(x_mid + iter.x)].distance < sdata.y)
			continue ;
		image_set_pixel(&(game->img), x_mid + iter.x, game->map.res[1] / 2
				- game->floor_coef + iter.y - (size / 2), color);
	}
}

void			render_sprite(int x_mid, t_point sprite, t_game *game)
{
	double	dist;
	double	size;
	t_point iter;

	dist = distance(game->p.pos, point(sprite.x * CUBE_SIZE + CUBE_SIZE / 2,
				sprite.y * CUBE_SIZE + CUBE_SIZE / 2));
	size = fabs(CUBE_SIZE / dist * game->p.proj_dist);
	if (size < game->map.res[0] || -x_mid < 0)
		iter.x = -size / 2 - 1;
	else
		iter.x = -x_mid - 1;
	while (++(iter.x) < size / 2 && x_mid + iter.x < game->map.res[0])
		draw_col(game, point(size, dist), iter, x_mid);
}

void			render_sprites(t_game *game)
{
	t_point *sprites;
	t_point	inc;
	t_point tmp;
	int		i;

	i = -1;
	sprites = sort_sprites(ft_lsttotab(game->spritecoords),
		ft_lstsize(game->spritecoords), game->p.pos);
	while (++i < ft_lstsize(game->spritecoords))
	{
		if (get_tile_at(point(sprites[i].x * CUBE_SIZE, sprites[i].y *
						CUBE_SIZE), game->map.map_d) != '2')
			continue ;
		inc = point((sprites[i].x * CUBE_SIZE + CUBE_SIZE / 2 - game->p.pos.x)
				* -1, sprites[i].y * CUBE_SIZE + CUBE_SIZE / 2 - game->p.pos.y);
		tmp.y = constrain(atan2(inc.y, inc.x) * (180 / PI), 0, 360);
		tmp.x = (360 - game->p.cam_angle) + (FOV / 2) - tmp.y;
		if (tmp.y > 270 && (360 - game->p.cam_angle) < 90)
			tmp.x = (360 - game->p.cam_angle) + 30 - tmp.y + 360;
		if ((360 - game->p.cam_angle) > 270 && tmp.y < 90)
			tmp.x = (360 - game->p.cam_angle) + 30 - tmp.y - 360;
		tmp.x = tmp.x * game->map.res[0] / FOV;
		render_sprite(tmp.x, sprites[i], game);
	}
	free(sprites);
}
