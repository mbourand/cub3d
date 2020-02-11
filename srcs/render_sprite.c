#include "cub3d.h"
#include <stdio.h>

t_point	*ft_lsttotab(t_list *list)
{
	t_point *res;
	int i;
	int size;

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

void		swap(t_point *p, t_point *p2)
{
	t_point tmp;

	tmp = *p;
	*p = *p2;
	*p2 = tmp;
}

t_point	*sort_sprites(t_point *sprites, int size, t_point pos)
{
	int j;

	j = -1;
	while (++j < size - 1)
	{
		if (distance(pos, point(sprites[j + 1].x * CUBE_SIZE + CUBE_SIZE / 2, sprites[j + 1].y * CUBE_SIZE + CUBE_SIZE / 2)) >
		distance(pos, point(sprites[j].x * CUBE_SIZE + CUBE_SIZE / 2, sprites[j].y * CUBE_SIZE + CUBE_SIZE / 2)))
		{
			swap(&(sprites[j + 1]), &(sprites[j]));
			j = -1;
		}
	}
	return (sprites);
}

void			render_sprite(int x_mid, t_point sprite, t_game *game)
{
	double dist;
	double size;
	t_point iter;
	t_point tex;

	dist = distance(game->p.pos, point(sprite.x * CUBE_SIZE + CUBE_SIZE / 2, sprite.y * CUBE_SIZE + CUBE_SIZE / 2));
	size = fabs(CUBE_SIZE / dist * game->p.proj_dist);
	iter = point(-size / 2, -1);
	while (++(iter.x) < size / 2)
	{
		if (size < game->map.res[1])
			iter.y = -1;
		else
			iter.y = (game->map.res[1] / 2 - game->floor_coef - size / 2) * -1;
		while (++(iter.y) < size)
		{
			tex = point((iter.x + size / 2) / size * game->tex_s.w, iter.y / size * game->tex_s.h);
			if (x_mid + iter.x < 0 || x_mid + iter.x >= game->map.res[0] || game->map.res[1] / 2 - game->floor_coef + iter.y - (size / 2) >= game->map.res[1] || tex.x < 0 || tex.y < 0 || image_get_color(game->tex_s, tex.x, tex.y) == TRANSPARENT_COLOR || game->p.rays[(int)(x_mid + iter.x)].distance < dist)
				continue ;
			image_set_pixel(&(game->img), x_mid + iter.x, game->map.res[1] / 2 - game->floor_coef + iter.y - (size / 2), image_get_color(game->tex_s, tex.x, tex.y));
		}
	}
}

void			render_sprites(t_game *game)
{
	t_point *sprites;
	t_point	inc;
	t_point tmp;
	int		size;
	int		i;

	i = -1;
	sprites = ft_lsttotab(game->spritecoords);
	size = ft_lstsize(game->spritecoords);
	sprites = sort_sprites(sprites, size, game->p.pos);
	while (++i < size)
	{
		inc = point((sprites[i].x * CUBE_SIZE + CUBE_SIZE / 2 - game->p.pos.x) * -1, sprites[i].y * CUBE_SIZE + CUBE_SIZE / 2 - game->p.pos.y);
		tmp.y = constrain(atan2(inc.y, inc.x) * (180 / PI), 0, 360);
		tmp.x = (360 - game->p.cam_angle) + (FOV / 2) - tmp.y;
		if (tmp.y > 270 && (360 - game->p.cam_angle) < 90) tmp.x = (360 - game->p.cam_angle) + 30 - tmp.y + 360;
		if ((360 - game->p.cam_angle) > 270 && tmp.y < 90) tmp.x = (360 - game->p.cam_angle) + 30 - tmp.y - 360;
		tmp.x = tmp.x * game->map.res[0] / FOV;
		render_sprite(tmp.x, sprites[i], game);
	}
	free(sprites);
}