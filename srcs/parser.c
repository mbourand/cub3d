/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:11 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/27 14:39:19 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static int		parse_parameters(int fd, t_map *map)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strncmp(line, "R", 1) && ft_strncmp(line, "NO", 2) &&
		ft_strncmp(line, "SO", 2) && ft_strncmp(line, "EA", 2) &&
		ft_strncmp(line, "WE", 2) && ft_strncmp(line, "S ", 2) &&
		ft_strncmp(line, "F", 1) && ft_strncmp(line, "C", 1) && line[0])
			error(ERR_UNDEF_PARAM);
		if (!ft_strncmp(line, "R", 1) && !parse_resolution(line, map))
			error(ERR_RESOLUTION);
		else if ((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) ||
		!ft_strncmp(line, "EA", 2) || !ft_strncmp(line, "WE", 2) ||
		!ft_strncmp(line, "S", 1)) && !parse_texture(line, map))
			error(ERR_TEXTURE);
		else if ((!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1)) &&
		!parse_color(line, map))
			error(ERR_COLOR);
		ft_strdel(&line);
		if (is_filled(*map))
			break ;
	}
	ft_strdel(&line);
	return (ret > -1);
}

static int		parse_description(int fd, t_map *map)
{
	int		ret;
	char	*line;
	t_list	*elem;
	int		end;

	while ((ret = get_next_line(fd, &line)))
	{
		if ((end = check_end(&line, map)) == 1)
			continue ;
		if (!(elem = ft_lstnew(line)))
			error(ERR_ALLOCATION);
		ft_lstadd_back(&map->map_d, elem);
	}
	ft_strdel(&line);
	if (ret == -1)
		error(ERR_FILE_READ);
	if (!check_map(map->map_d))
		error(ERR_MAP);
	if (!format_description(map))
		error(ERR_ALLOCATION);
	return (ret > -1);
}

int				parse_map(char *filename, t_map *map)
{
	int fd;

	if (!ft_endswith(filename, ".cub"))
		error(ERR_NOT_CUB);
	if ((fd = open(filename, O_RDONLY)) <= 0)
		error(ERR_FILE_OPEN);
	if (!parse_parameters(fd, map))
		error(ERR_FILE_READ);
	if (!is_filled(*map))
		error(ERR_MISSING_PARAM);
	if (!parse_description(fd, map))
		error(ERR_FILE_READ);
	return (1);
}
