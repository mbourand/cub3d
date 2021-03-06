/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:05:45 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/25 16:25:56 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_hud(t_game *game)
{
	if (game->map.res[0] > MINIMAP_SIZE * 2 && game->map.res[1] > MINIMAP_SIZE
			* 2)
		render_minimap(game);
	render_scope(game);
}
