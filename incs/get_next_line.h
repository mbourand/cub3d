/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:02:47 by mbourand          #+#    #+#             */
/*   Updated: 2020/01/14 19:27:38 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

size_t	ft_strlenuntil(const char *s, char c);
char	*ft_strdupuntil(const char *s1, char c);
char	*ft_strjoinuntil(char *s1, char const *s2, char c);
int		get_next_line(int fd, char **line);
#endif
