#include "cub3d.h"

void	render_scope(t_game *game)
{
	t_point iter;

	iter = point(-1, -1);
	while (++(iter.x) < 10)
	{
		iter.y = -1;
		while (++(iter.y) < 2)
		{
			image_set_pixel(&(game->img), game->map.res[0] / 2 - SCOPE_OFFSET - iter.x, game->map.res[1] / 2 + iter.y,
					0xFFFFFF - image_get_color(game->img, game->map.res[0] / 2 - SCOPE_OFFSET - iter.x, game->map.res[1] / 2 + iter.y));
			image_set_pixel(&(game->img), game->map.res[0] / 2 + SCOPE_OFFSET + iter.x, game->map.res[1] / 2 + iter.y,
					0xFFFFFF - image_get_color(game->img, game->map.res[0] / 2 + SCOPE_OFFSET + iter.x, game->map.res[1] / 2 + iter.y));
			image_set_pixel(&(game->img), game->map.res[0] / 2 + iter.y, game->map.res[1] / 2 - SCOPE_OFFSET - iter.x,
				0xFFFFFF - image_get_color(game->img, game->map.res[0] / 2 + iter.y, game->map.res[1] / 2 - SCOPE_OFFSET - iter.x));
			image_set_pixel(&(game->img), game->map.res[0] / 2 + iter.y, game->map.res[1] / 2 + SCOPE_OFFSET + iter.x,
			       0xFFFFFF - image_get_color(game->img, game->map.res[0] / 2 + iter.y, game->map.res[1] / 2 + SCOPE_OFFSET + iter.x));
		}
	}
}
