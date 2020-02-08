/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:29:18 by mbourand          #+#    #+#             */
/*   Updated: 2019/11/07 10:58:14 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*cb;

	i = 0;
	cb = (unsigned char*)b;
	while (i < len)
	{
		cb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
