/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:22:00 by mbourand          #+#    #+#             */
/*   Updated: 2020/01/17 16:43:06 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (0);
	elem->content = content;
	elem->next = 0;
	return (elem);
}
