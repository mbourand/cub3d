/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:53:07 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/25 16:18:58 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_pixels(t_game *game, t_point iter)
{
	image_set_pixel(&(game->img), game->map.res[0] / 2 - SCOPE_OFFSET -
			iter.x, game->map.res[1] / 2 + iter.y,
			0xFFFFFF - image_get_color(game->img, game->map.res[0] / 2
			- SCOPE_OFFSET - iter.x, game->map.res[1] / 2 + iter.y));
	image_set_pixel(&(game->img), game->map.res[0] / 2 + SCOPE_OFFSET
			+ iter.x, game->map.res[1] / 2 + iter.y,
			0xFFFFFF - image_get_color(game->img, game->map.res[0] / 2
			+ SCOPE_OFFSET + iter.x, game->map.res[1] / 2 + iter.y));
	image_set_pixel(&(game->img), game->map.res[0] / 2 + iter.y,
			game->map.res[1] / 2 - SCOPE_OFFSET - iter.x, 0xFFFFFF -
			image_get_color(game->img, game->map.res[0] / 2 + iter.y,
				game->map.res[1] / 2 - SCOPE_OFFSET - iter.x));
	image_set_pixel(&(game->img), game->map.res[0] / 2 + iter.y,
			game->map.res[1] / 2 + SCOPE_OFFSET + iter.x, 0xFFFFFF
			- image_get_color(game->img, game->map.res[0] / 2 +
				iter.y, game->map.res[1] / 2 + SCOPE_OFFSET + iter.x));
}

void		render_scope(t_game *game)
{
	t_point iter;

	iter = point(-1, -1);
	while (++(iter.x) < 10)
	{
		iter.y = -1;
		while (++(iter.y) < 2)
			display_pixels(game, iter);
	}
}
