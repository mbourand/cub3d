/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:16:14 by mbourand          #+#    #+#             */
/*   Updated: 2020/03/02 16:46:27 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_key_index(int key)
{
	static int	keys[8] = {K_UP, K_DOWN, K_LEFT, K_RIGHT,
		K_CAMLEFT, K_CAMRIGHT, K_CAMUP, K_CAMDOWN};
	int			i;

	i = 0;
	while (i < 8)
	{
		if (keys[i] == key)
			return (i);
		i++;
	}
	return (-1);
}

int		key_released(int key, void *param)
{
	t_game	*game;
	int		ind;

	game = (t_game*)param;
	if ((ind = get_key_index(key)) != -1)
		game->keys[ind] = -1;
	return (0);
}

int		key_pressed(int key, void *param)
{
	t_game		*game;
	int			ind;

	game = (t_game*)param;
	if ((ind = get_key_index(key)) != -1)
		game->keys[ind] = key;
	if (key == K_ESC)
		quit(game);
	else if (key == K_SCREENSHOT)
		render(game, 1);
	return (0);
}
