#include "cub3d.h"

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
		i = (game->map.res[1] / 2 - game->floor_coef - height / 2) * -1;
	while (++i < height)
	{
		if (game->map.res[1] / 2 - game->floor_coef + i - (height / 2) >= game->map.res[1])
		   break ;
		tex_x = ray->wall / (double)(CUBE_SIZE) * tex.w;
		tex_z = i / height * tex.h;
		if (tex_x < 0 || tex_z < 0)
			continue ;
		image_set_pixel(&(game->img), x, game->map.res[1] / 2 - game->floor_coef + i - (height / 2), image_get_color(tex, tex_x, tex_z));
	}
}