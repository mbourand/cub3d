/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:03:22 by mbourand          #+#    #+#             */
/*   Updated: 2020/01/23 12:18:56 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *list, size_t index)
{
	size_t i;

	i = 0;
	if (!list)
		return (0);
	while (i < index && list)
	{
		list = list->next;
		i++;
	}
	return (list);
}
