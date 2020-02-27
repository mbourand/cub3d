/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:45:59 by mbourand          #+#    #+#             */
/*   Updated: 2020/02/27 14:40:29 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_end(char **line, t_map *map)
{
	static int end;

	if (end == 1)
		error(ERR_MAP);
	if (!(*line)[0])
	{
		if (ft_lstsize(map->map_d) == 0)
		{
			ft_strdel(line);
			return (1);
		}
		end++;
	}
	return (0);
}

int		char_count(char *line)
{
	int i;
	int len;

	len = 0;
	i = -1;
	while (line[++i])
	{
		if (ft_skipcharset(line + i, "012NSWE") != 0)
			len++;
	}
	return (len);
}

int		check_line(t_list *tmp, char **i_content, int *player,
		char *fst_content)
{
	int		i;
	t_point ret;

	i = 0;
	*i_content = (char*)(tmp->content);
	while ((*i_content)[i])
	{
		if ((ret.x = ft_skipcharset(*i_content + i, "012NSWE")) != 1)
			return (0);
		if (ft_skipcharset(*i_content + i, "NSWE") != 0)
		{
			if (*player == 1)
				return (0);
			*player = 1;
		}
		if ((ret.y = ft_skipcharset(*i_content + i + 1, " ")) == 0 &&
				(*i_content)[i + 1])
			return (0);
		i += 1 + ret.y;
	}
	return (!(char_count(*i_content) != char_count(fst_content) ||
		char_count(*i_content) == 0 || (*i_content)[0] != '1' ||
		(*i_content)[ft_strlen(*i_content) - 1] != '1'));
}

int		check_map(t_list *map)
{
	char	*fst_content;
	char	*i_content;
	t_list	*tmp;
	int		player;

	if (!map)
		return (0);
	player = 0;
	tmp = map;
	fst_content = (char*)(map->content);
	if (!ft_onlypattern(fst_content, "1 ") || ft_strlen(fst_content) == 0)
		return (0);
	while (tmp)
	{
		if (!check_line(tmp, &i_content, &player, fst_content))
			return (0);
		tmp = tmp->next;
	}
	if (!ft_onlypattern(ft_lstlast(map)->content, "1 ") ||
			ft_strlen(ft_lstlast(map)->content) != ft_strlen(fst_content)
			|| player == 0)
		return (0);
	return (1);
}
