/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:43:31 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/08 16:58:14 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_event(void *param)
{
	t_game *game;

	game = (t_game*)param;
	quit(game);
	return (0);
}
