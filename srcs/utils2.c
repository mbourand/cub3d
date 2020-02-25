/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:49:08 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/25 16:52:54 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point			point(double x, double y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

t_list		*point_lstnew(double x, double y)
{
	t_point	*point;
	t_list	*elem;

	if (!(point = malloc(sizeof(t_point))))
		error(ERR_ALLOCATION);
	point->x = x;
	point->y = y;
	if (!(elem = ft_lstnew(point)))
		error(ERR_ALLOCATION);
	return (elem);
}
