/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:29 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/13 03:10:47 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		parse_resolution(char *s, t_map *map)
{
	int i;

	if ((map->res)[0] != -1)
		return (0);
	i = 1;
	while (s[i] == ' ')
		i++;
	if (!s[i] || i == 1)
		return (0);
	map->res[0] = min(ft_atoi(s + i), MAX_WIDTH);
	if (map->res[0] <= 0)
		return (0);
	i += ft_numberlen(map->res[0], 10);
	if (s[i] != ' ' || !ft_isdigit(s[i + 1]))
		return (0);
	i++;
	map->res[1] = min(ft_atoi(s + i), MAX_HEIGHT);
	if (s[i + ft_numberlen(map->res[1], 10)])
		return (0);
	if (map->res[1] <= 0)
		return (0);
	return (1);
}

int		parse_texture(char *line, t_map *map)
{
	int i;

	i = (ft_strncmp(line, "SO", 2) && !ft_strncmp(line, "S", 1) ? 1 : 2);
	if (line[i] != ' ')
		return (0);
	if (!line[(i += ft_skipcharset(line + i, " "))] || i == 0)
		return (0);
	if (!ft_strncmp(line, "NO", 2) && !map->tex_no)
		map->tex_no = ft_strdup(line + 2 + ft_skipcharset(line + 2, " "));
	else if (!ft_strncmp(line, "SO", 2) && !map->tex_so)
		map->tex_so = ft_strdup(line + 2 + ft_skipcharset(line + 2, " "));
	else if (!ft_strncmp(line, "EA", 2) && !map->tex_ea)
		map->tex_ea = ft_strdup(line + 2 + ft_skipcharset(line + 2, " "));
	else if (!ft_strncmp(line, "WE", 2) && !map->tex_we)
		map->tex_we = ft_strdup(line + 2 + ft_skipcharset(line + 2, " "));
	else if (!ft_strncmp(line, "S", 1) && !map->tex_s)
		map->tex_s = ft_strdup(line + 1 + ft_skipcharset(line + 1, " "));
	else
		return (0);
	return (1);
}

int		parse_color(char *line, t_map *map)
{
	int i;
	int rgb[3];
	int color;

	i = 1 + ft_skipcharset(line + 1, " ");
	if (!line[i] || i == 1)
		return (0);
	rgb[0] = ft_atoi(line + i);
	i += ft_numberlen(rgb[0], 10);
	if (line[i] != ',' || !ft_isdigit(line[i + 1]))
		return (0);
	rgb[1] = ft_atoi(line + i + 1);
	i += ft_numberlen(rgb[1], 10) + 1;
	if (line[i] != ',' || !ft_isdigit(line[i + 1]))
		return (0);
	rgb[2] = ft_atoi(line + i + 1);
	if (line[i + ft_numberlen(rgb[2], 10) + 1] || (color = rgbtoint(rgb)) == -1)
		return (0);
	if (line[0] == 'F' && map->col_f == -1)
		map->col_f = color;
	else if (line[0] == 'C' && map->col_c == -1)
		map->col_c = color;
	else
		return (0);
	return (1);
}

int		is_filled(t_map map)
{
	return (map.res[0] != -1 && map.res[1] != -1 &&
			map.tex_no && map.tex_so && map.tex_ea && map.tex_we && map.tex_s &&
			map.col_f != -1 && map.col_c != -1);
}
