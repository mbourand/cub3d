#include "cub3d.h"
#include <stdio.h>

void	render_background(t_game *game, int x, int h)
{
	int j;
	
	j = -1;
	while (++j < game->map.res[1] / 2 - game->floor_coef - (h / 2))
		image_set_pixel(&(game->img), x, j, (j < game->map.res[1] / 2 - game->floor_coef ? game->map.col_c : game->map.col_f));
	j = game->map.res[1] / 2 - game->floor_coef + (h / 2);
	while (++j < game->map.res[1])
		image_set_pixel(&(game->img), x, j, (j < game->map.res[1] / 2 - game->floor_coef ? game->map.col_c : game->map.col_f));
}

void	render_wall(t_game *game, t_ray *ray, int x)
{
	double		height;
	t_image		tex;
	int			tex_x;
	int			tex_z;
	int			i;

	height = ray->distance * cos(to_radians(game->p.cam_angle - ray->angle));
	height = fabs(CUBE_SIZE / height * game->p.proj_dist);
	tex = get_texture_face(game, ray->face);
	if (height < game->map.res[1])
		i = -1;
	else
		i = height / 2 + game->floor_coef - game->map.res[1] / 2 - 1;
	if (i < -1)
		i = -1;
	render_background(game, x, height);
	while (++i < height)
	{
		if (game->map.res[1] / 2 - game->floor_coef + i - (height / 2) >= game->map.res[1])
		   break ;
		tex_x = ray->wall / (double)(CUBE_SIZE) * tex.w;
		tex_z = i / height * tex.h;
		image_set_pixel(&(game->img), x, game->map.res[1] / 2 - game->floor_coef + i - (height / 2), image_get_color(tex, tex_x, tex_z));
	}
}