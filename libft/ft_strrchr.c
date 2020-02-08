/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:00:16 by mbourand          #+#    #+#             */
/*   Updated: 2019/11/07 09:52:31 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int last;

	last = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = i;
		i++;
	}
	if (c == 0)
		return ((char*)(s + i));
	else if (last == -1)
		return (0);
	return ((char*)(s + last));
}
