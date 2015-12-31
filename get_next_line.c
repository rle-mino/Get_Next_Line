/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:06:35 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/31 14:44:26 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char			*left(char *buf1, char **buf2)
{
	size_t			i;

	*buf2 = ft_strdup(*buf2 + 1);
	i = 0;
	while (buf1[i] != '\n')
		i++;
	while (buf1[i])
	{
		buf1[i] = '\0';
		i++;
	}
	return (buf1);
}

char			*right(char *buf2)
{
	char	*line;
	int		i;

	i = 0;
	while (buf2[i] != '\n')
		i++;
	line = (char *)malloc(i + 1);
	i = 0;
	while (buf2[i] != '\n')
	{
		line[i] = buf2[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char			*top(char *buf)
{
	int		i;

	i = 0;
	if (buf[i] == '\n')
	{
		buf = buf + 1;
		return (buf);
	}
	while (buf[i] != '\n')
		i++;
	buf = buf + i + 1;
	return (buf);
}

int					get_next_line(int const fd, char **line)
{
	static t_struct		*ko = NULL;
	int					rd;

	if (!ko)
	{
		ko = (t_struct *)malloc(sizeof(t_struct));
		ko->buf1 = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
		ko->buf2 = NULL;
	}
	*line = (char *)ft_memalloc(1);
	if (ko->k && ko->buf2)
	{
		if (ft_strchr(ko->buf2, '\n') != NULL)
		{
			//printf("before %s\n", *line);
			*line = right(ko->buf2);
			ko->buf2 = top(ko->buf2);
			//printf("after %s\n", *line);
			return (1);
		}
		else
			*line = ft_strjoin(*line, ko->buf2);
	}
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, ko->buf1, BUFF_SIZE);
		ko->buf1[BUFF_SIZE] = '\0';
		if ((ko->buf2 = ft_strchr(ko->buf1, '\n')) != NULL)
		{
			rd = 0;
			*line = ft_strjoin(*line, left(ko->buf1, &ko->buf2));
			ko->k = 1;
			return (1);
		}
		*line = ft_strjoin(*line, ko->buf1);
	}
	return (0);
}
