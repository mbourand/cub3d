#include "cub3d.h"

void	render_player(t_game *game)
{
	t_point iter;

	iter = point(-1, -1);
	while (++(iter.x) < 6)
	{
		iter.y = -1;
		while (++(iter.y) < 6)
			image_set_pixel(&(game->img), game->map.res[0] - 10 - MINIMAP_SIZE / 2 + iter.x - 5, 10 + MINIMAP_SIZE / 2 + iter.y - 5, 0xFF0000);
	}
}

void	render_minimap(t_game *game)
{
	t_point iter;
	int		wall_size;
	t_point coords;
	char	tile;

	wall_size = MINIMAP_SIZE / 5;
	iter = point(-1, -1);
	while (++(iter.x) < MINIMAP_SIZE)
	{
		iter.y = -1;
		while (++(iter.y) < MINIMAP_SIZE)
		{
			coords = point(game->p.pos.x - ((iter.x - MINIMAP_SIZE / 2) * CUBE_SIZE / wall_size),
				game->p.pos.y + ((iter.y - MINIMAP_SIZE / 2) * CUBE_SIZE / wall_size));
			if ((tile = get_tile_at(coords, game->map.map_d)) == '1' || tile == -1)
				image_set_pixel(&(game->img), game->map.res[0] - 10 - iter.x, 10 + iter.y, 0xFFFFFF);
			else if (tile == '2' &&
					(int)coords.x % CUBE_SIZE > CUBE_SIZE * 0.4 && (int)coords.x % CUBE_SIZE < CUBE_SIZE * 0.6 &&
					(int)coords.y % CUBE_SIZE > CUBE_SIZE * 0.4 && (int)coords.y % CUBE_SIZE < CUBE_SIZE * 0.6)
				image_set_pixel(&(game->img), game->map.res[0] - 10 - iter.x, 10 + iter.y, 0xFFFF00);
			else
				image_set_pixel(&(game->img), game->map.res[0] - 10 - iter.x, 10 + iter.y, 0x000000);
		}
	}
	render_player(game);
}

void	render_hud(t_game *game)
{
	if (game->map.res[0] > MINIMAP_SIZE * 2 && game->map.res[1] > MINIMAP_SIZE * 2)
		render_minimap(game);
}