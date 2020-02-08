/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:11:08 by mbourand          #+#    #+#             */
/*   Updated: 2020/01/17 18:24:33 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_endswith(char *str, char *end)
{
	int i;
	int len;

	i = ft_strlen(end);
	if ((len = ft_strlen(str)) < i)
		return (0);
	while (i > 0)
	{
		if (str[len - i] != end[ft_strlen(end) - i])
			return (0);
		i--;
	}
	return (1);
}
