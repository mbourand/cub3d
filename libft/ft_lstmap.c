/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:56:37 by mbourand          #+#    #+#             */
/*   Updated: 2019/11/12 11:02:23 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*current;
	t_list	*elem;

	if (!lst || !(map = ft_lstnew(f(lst->content))))
		return (0);
	current = map;
	while (lst)
	{
		if (!(elem = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&map, del);
			return (0);
		}
		current->next = elem;
		lst = lst->next;
		current = current->next;
	}
	current = 0;
	return (map);
}
