/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:29 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/26 16:05:06 by mbourand         ###   ########.fr       */
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
	if (s[i] != ' ' || !ft_isdigit(s[i + ft_skipcharset(s + i, " ")]))
		return (0);
	i += ft_skipcharset(s + i, " ");
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

int		check_split(char *line, char **split)
{
	t_point iter;

	iter = point(0, 0);
	while (split[(int)iter.x])
		iter.x++;
	if (iter.x != 3)
		return (0);
	iter.x = -1;
	while (++(iter.x) < ft_strlen(line))
	{
		iter.y = (line[(int)iter.x] == ',') ? iter.y + 1 : 0;
		if (iter.y == 2)
			return (0);
	}
	iter = point(-1, -1);
	while (++(iter.x) < 3)
	{
		iter.y = -1;
		while (++(iter.y) < ft_strlen(split[(int)iter.x]))
			if (!ft_isdigit(split[(int)iter.x][(int)iter.y]) &&
(split[(int)iter.x][(int)iter.y] != ' ' ||
ft_skipcharset(split[(int)iter.x], " ") == ft_strlen(split[(int)iter.x])))
				return (0);
	}
	return (1);
}

int		parse_color(char *line, t_map *map)
{
	int		i;
	int		rgb[3];
	int		col;
	char	**split;

	if (line[1] != ' ')
		error(ERR_COLOR);
	split = ft_split(line + 1, ',');
	if (!check_split(line, split) ||
!ft_isdigit(split[2][ft_strlen(split[2]) - 1]) || (col = rgbtoint(rgb)) == -1)
		error(ERR_COLOR);
	if (line[0] == 'F' && map->col_f == -1)
		map->col_f = col;
	else if (line[0] == 'C' && map->col_c == -1)
		map->col_c = col;
	else
		error(ERR_COLOR);
	i = -1;
	while (++i < 3)
	{
		rgb[i] = ft_atoi(split[i]);
		free(split[i]);
	}
	free(split);
	return (1);
}

int		is_filled(t_map map)
{
	return (map.res[0] != -1 && map.res[1] != -1 &&
			map.tex_no && map.tex_so && map.tex_ea && map.tex_we && map.tex_s &&
			map.col_f != -1 && map.col_c != -1);
}
