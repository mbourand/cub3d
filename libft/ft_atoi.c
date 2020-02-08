/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:11:52 by mbourand          #+#    #+#             */
/*   Updated: 2019/11/07 13:33:51 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(char c)
{
	return (c == ' ' || c == '\v' || c == '\f' || c == '\r' || c == '\n'
		|| c == '\t');
}

int			ft_atoi(const char *str)
{
	double				res;
	int					sign;
	int					i;

	i = 0;
	while (whitespace(str[i]))
		i++;
	sign = (str[i] == '-' ? -1 : 1);
	i += (str[i] == '-' || str[i] == '+' ? 1 : 0);
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (res * sign < LONG_MIN)
			return (0);
		else if (res * sign > LONG_MAX)
			return (-1);
	}
	return (res * sign);
}
