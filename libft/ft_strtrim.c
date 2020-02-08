/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:03:35 by mbourand          #+#    #+#             */
/*   Updated: 2019/11/07 10:06:07 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		contains(char const *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		total_len(char const *s1, char const *set)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s1[i] && contains(set, s1[i]))
		i++;
	while (s1[i])
	{
		res++;
		i++;
	}
	i--;
	while (contains(set, s1[i]) && i > 0)
	{
		res--;
		i--;
	}
	return (res < 0 ? 0 : res);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	if (!s1 || !set)
		return (0);
	len = total_len(s1, set);
	i = 0;
	j = 0;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s1[i] && contains(set, s1[i]))
		i++;
	while (j < len)
	{
		res[j] = s1[i + j];
		j++;
	}
	res[j] = 0;
	return (res);
}
