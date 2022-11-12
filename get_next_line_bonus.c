/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:21:05 by zbentale          #+#    #+#             */
/*   Updated: 2022/11/12 14:35:13 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_all_line(char *a, int fd)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc(sizeof(char) * ((size_t)(BUFFER_SIZE + 1)));
	if (!buff)
		return (NULL);
	while (!ft_strchr(a, '\n') && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(a);
			return (NULL);
		}
		buff[i] = '\0';
		a = ft_strjoin(a, buff);
		if (!a)
			return (NULL);
	}
	free(buff);
	return (a);
}

char	*get_return(char *a)
{
	char	*b;
	int		i;

	i = 0;
	if (!a[i])
		return (NULL);
	while (a[i] && a[i] != '\n')
		i++;
	b = malloc((i + 2) * sizeof(char));
	if (!b)
		return (NULL);
	i = 0;
	while (a[i] && a[i] != '\n')
	{
		b[i] = a[i];
		i++;
	}
	if (a[i] == '\n')
	{
		b[i] = '\n';
		i++;
	}
	b[i] = '\0';
	return (b);
}

char	*get_the_rest(char *a)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	while (a[i] && a[i] != '\n')
		i++;
	if (!a[i])
	{
		free(a);
		return (NULL);
	}
	c = malloc(((ft_strlen(a) - i) + 1) * sizeof(char));
	if (!c)
		return (NULL);
	i++;
	while (a[i])
	{
		c[j++] = a[i++];
	}
	c[j] = '\0';
	free(a);
	return (c);
}

char	*get_next_line(int fd)
{
	static char	*a[10240];
	char		*b;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	a[fd] = get_all_line(a[fd], fd);
	if (!a[fd])
		return (NULL);
	b = get_return(a[fd]);
	a[fd] = get_the_rest(a[fd]);
	return (b);
}
