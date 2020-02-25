/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_description.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:04:03 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/25 16:05:20 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_line_len(char *line)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (line[++i])
	{
		if (line[i] != ' ')
			len++;
	}
	return (len);
}

int		format_description(t_map *map)
{
	t_list	*tmp;
	char	*line;
	int		len;
	t_point	iter;
	char	*res;

	tmp = map->map_d;
	while (tmp)
	{
		line = (char*)tmp->content;
		len = get_line_len(line);
		if (!(res = (char*)malloc(sizeof(char*) * (len + 1))))
			return (0);
		iter = point(0, 0);
		while (line[(int)iter.x])
		{
			res[(int)iter.y++] = line[(int)iter.x];
			iter.x += ft_skipcharset(line + (int)iter.x + 1, " ") + 1;
		}
		res[len] = 0;
		ft_strdel((char**)(&(tmp->content)));
		tmp->content = res;
		tmp = tmp->next;
	}
	return (1);
}
