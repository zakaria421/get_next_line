/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:21:15 by zbentale          #+#    #+#             */
/*   Updated: 2022/11/12 14:28:32 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
#endif
