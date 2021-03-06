/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:02:45 by mbourand          #+#    #+#             */
/*   Updated: 2020/03/02 16:11:43 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_angle(int key)
{
	if (key == K_UP)
		return (180);
	if (key == K_DOWN)
		return (0);
	if (key == K_LEFT)
		return (90);
	if (key == K_RIGHT)
		return (270);
	return (0);
}

double	get_char_angle(char c)
{
	if (c == 'N')
		return (90);
	if (c == 'S')
		return (270);
	if (c == 'W')
		return (0.00001);
	if (c == 'E')
		return (180);
	return (0);
}
