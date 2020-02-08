/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:37:00 by mbourand          #+#    #+#             */
/*   Updated: 2019/11/12 08:55:48 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		size;
	char				*res;

	i = -1;
	size = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		if (!(res = (char*)malloc(sizeof(char))))
			return (0);
		res[0] = 0;
		return (res);
	}
	while (s[size + start] && size < len)
		size++;
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (++i < size)
		res[i] = s[i + start];
	res[i] = 0;
	return (res);
}
