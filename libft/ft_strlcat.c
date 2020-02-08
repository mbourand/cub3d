/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:43:54 by mbourand          #+#    #+#             */
/*   Updated: 2019/11/12 11:23:07 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (dstsize <= dlen)
		return (slen + dstsize);
	slen += dlen;
	while (src[i] && dlen + 1 < dstsize)
	{
		dst[dlen] = src[i];
		i++;
		dlen++;
	}
	dst[dlen] = 0;
	return (slen);
}
