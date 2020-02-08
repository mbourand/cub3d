/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:11 by mbourand          #+#    #+#             */
/*   Updated: 2020/01/29 13:59:14 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

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
			error("Un paramètre donné est indéfini.");
		if (!ft_strncmp(line, "R", 1) && !parse_resolution(line, map))
			error("La résolution donnée est incorrecte.");
		else if ((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) ||
		!ft_strncmp(line, "EA", 2) || !ft_strncmp(line, "WE", 2) ||
		!ft_strncmp(line, "S", 1)) && !parse_texture(line, map))
			error("Une texture donnée est incorrecte.");
		else if ((!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1)) &&
		!parse_color(line, map))
			error("Une couleur donnée est incorrecte.");
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

	while ((ret = get_next_line(fd, &line)))
	{
		if (!line[0])
		{
			free(line);
			continue ;
		}
		if (!(elem = ft_lstnew(line)))
			error("Une erreur d'allocation est survenue.");
		ft_lstadd_back(&map->map_d, elem);
	}
	ft_strdel(&line);
	if (ret == -1)
		error("Le fichier donné en argument n'a pas pu être lu.");
	if (!check_map(map->map_d))
		error("La carte donnée est incorrecte.");
	return (ret > -1);
}

int				parse_map(char *filename, t_map *map)
{
	int fd;

	if (!ft_endswith(filename, ".cub"))
		error("Le fichier donné en argument ne contient pas l'extention .cub.");
	if ((fd = open(filename, O_RDONLY)) <= 0)
		error("Le fichier donné en argument n'a pas pu être ouvert.");
	if (!parse_parameters(fd, map))
		error("Le fichier donné en argument n'a pas pu être lu.");
	if (!is_filled(*map))
		error("Un ou plusieurs paramètres sont manquants dans le fichier.");
	if (!parse_description(fd, map))
		error("Le fichier donné en argument n'a pas pu être lu.");
	return (1);
}
