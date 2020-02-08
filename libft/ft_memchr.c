/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:16:38 by mbourand          #+#    #+#             */
/*   Updated: 2019/11/07 10:58:24 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	cs = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
			return ((void*)(s + i));
		i++;
	}
	return (0);
}
