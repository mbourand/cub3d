/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:43:28 by mbourand          #+#    #+#             */
/*   Updated: 2019/11/07 10:19:09 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	i = 0;
	if (!dst && !src)
		return (0);
	if (dst < src)
	{
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	else
		while (len-- > 0)
			cdst[len] = csrc[len];
	return (dst);
}
