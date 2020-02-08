/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:05:03 by mbourand          #+#    #+#             */
/*   Updated: 2020/01/14 22:08:09 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	newline(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	int				bytes;
	static char		buffer[BUFFER_SIZE + 1];

	if (!line)
		return (-1);
	if (BUFFER_SIZE == 0)
	{
		*line = 0;
		return (-1);
	}
	*line = ft_strdupuntil("", 0);
	while (newline(buffer) == -1)
	{
		if (!(*line = ft_strjoinuntil(*line, buffer, '\n')))
			return (-1);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (bytes);
	}
	if (!(*line = ft_strjoinuntil(*line, buffer, '\n')))
		return (-1);
	ft_strlcpy(buffer, buffer + newline(buffer) + 1, BUFFER_SIZE);
	return (1);
}
