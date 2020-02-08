/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 09:26:51 by mbourand          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:44 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenuntil(const char *s, char c)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_strdupuntil(const char *s1, char c)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = (char*)malloc(sizeof(char) * (ft_strlenuntil(s1, '\n') + 1))))
		return (0);
	while (s1[i] && s1[i] != c)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*ft_strjoinuntil(char *s1, char const *s2, char c)
{
	char	*res;
	int		i;
	int		s1_len;
	int		s2_len;

	if (!s1)
		return (ft_strdupuntil(s2, '\n'));
	if (!s2)
		return (0);
	s1_len = ft_strlenuntil(s1, 0);
	s2_len = 0;
	while (s2[s2_len] && s2[s2_len] != c)
		s2_len++;
	i = -1;
	if (!(res = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	while (s1[++i])
		res[i] = s1[i];
	i = -1;
	while (s2[++i] && s2[i] != c)
		res[s1_len + i] = s2[i];
	res[s1_len + i] = 0;
	free(s1);
	return (res);
}
