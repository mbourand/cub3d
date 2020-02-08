/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlypattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:10:01 by mbourand          #+#    #+#             */
/*   Updated: 2020/01/17 18:28:15 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_onlypattern(char *str, char *pattern)
{
	int i;
	int j;
	int patternlen;

	patternlen = ft_strlen(pattern);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != pattern[j])
			return (0);
		i++;
		j++;
		j = j % patternlen;
	}
	return (1);
}
