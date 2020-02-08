/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:23:52 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/06 16:19:39 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		to_radians(double angle)
{
	return (PI / 180 * angle);
}

double		constrain(double d, double min, double max)
{
	if (max < min)
		return (d);
	if (max == min)
		return (max);
	while (d < min)
		d += (max - min);
	while (d > max)
		d -= (max - min);
	return (d);
}

double		min(double d, double e)
{
	return (d < e ? d : e);
}
