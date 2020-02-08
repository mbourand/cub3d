/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:53:07 by mbourand          #+#    #+#             */
/*   Updated: 2020/01/17 18:26:42 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numberlen(int number, unsigned int baselen)
{
	size_t			res;
	unsigned int	un;

	res = 1 + (number < 0);
	un = (number < 0 ? -number : number);
	while (un / baselen > 0)
	{
		res++;
		un /= baselen;
	}
	return (res);
}
