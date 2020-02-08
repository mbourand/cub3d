/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:28:07 by mbourand          #+#    #+#             */
/*   Updated: 2019/11/07 11:46:29 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_parts(const char *s, char c)
{
	int i;
	int res;

	res = 1;
	i = 0;
	if (!s[0])
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i])
				res++;
		}
		else
			i++;
	}
	return (res);
}

static int		count_len(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void		copy(char *dst, const char *src, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

static int		skip_matches(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		len;
	int		word;
	int		parts;

	if (!s)
		return (0);
	word = 0;
	i = skip_matches(s, c);
	parts = count_parts(s + i, c);
	if (!(res = (char**)malloc(sizeof(char*) * (parts + 1))))
		return (0);
	while (s[i])
	{
		len = count_len(s + i, c);
		if (!(res[word] = (char*)malloc(sizeof(char) * (len + 1))))
			return (0);
		copy(res[word++], s + i, len);
		i += len;
		while (s[i] == c && s[i])
			i++;
	}
	res[parts] = 0;
	return (res);
}
