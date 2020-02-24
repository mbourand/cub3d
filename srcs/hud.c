#include "cub3d.h"

void	render_hud(t_game *game)
{
	if (game->map.res[0] > MINIMAP_SIZE * 2 && game->map.res[1] > MINIMAP_SIZE * 2)
		render_minimap(game);
	render_scope(game);
}