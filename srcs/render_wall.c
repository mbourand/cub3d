#include "cub3d.h"

void	render_wall(t_game *game, int x)
{
	double		height;
	t_image		tex;
	int			tex_x;
	int			tex_z;
	int			i;

	height = game->p.ray.distance * cos(to_radians(game->p.cam_angle - game->p.ray.angle));
	height = fabs(CUBE_SIZE / height * game->p.proj_dist);
	tex = get_texture_face(game, game->p.ray.face);
	if (height < game->map.res[1])
		i = -1;
	else
		i = (game->map.res[1] / 2 - height / 2) * -1;
	while (++i < height)
	{
		if (game->map.res[1] / 2 + i - (height / 2) >= game->map.res[1])
		   break ;
		tex_x = game->p.ray.wall / (double)(CUBE_SIZE) * tex.w;
		tex_z = i / height * tex.h;
		image_set_pixel(&(game->img), x, game->map.res[1] / 2 + i - (height / 2), image_get_color(tex, tex_x, tex_z));
	}
}