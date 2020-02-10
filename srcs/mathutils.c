/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:23:52 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/09 22:13:45 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		distance(t_point p, t_point p2)
{
	t_point dist;

	dist.x = p.x - p2.x;
	dist.y = p.y - p2.y;
	return (sqrt((dist.x * dist.x) + (dist.y * dist.y)));
}

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

t_point		point(double x, double y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

int			rgbtoint(int rgb[3])
{
	int color;

	if (rgb[0] > 255 || rgb[0] < 0 || rgb[1] > 255 || rgb[1] < 0 ||
			rgb[2] > 255 || rgb[2] < 0)
		return (-1);
	color = (rgb[0] << 16);
	color += (rgb[1] << 8);
	color += rgb[2];
	return (color);
}