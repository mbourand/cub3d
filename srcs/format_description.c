#include "cub3d.h"

int		get_line_len(char *line)
{
	int i;
	int len;

	i = -1;
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