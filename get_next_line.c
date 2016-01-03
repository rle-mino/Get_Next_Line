/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:06:35 by rle-mino          #+#    #+#             */
/*   Updated: 2016/01/03 20:04:31 by rle-mino         ###   ########.fr       */
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

static char			*right(char *buf2)
{
	char	*line;
	int		i;

	i = 0;
	while (buf2[i] != '\n')
		i++;
	line = (char *)ft_memalloc(i + 1);
	i = -1;
	while (buf2[++i] != '\n')
		line[i] = buf2[i];
	line[i] = '\0';
	return (line);
}

static char			*top(char *buf, t_struct **gnl)
{
	int		i;

	i = 0;
	(*gnl)->bin = buf;
	if (buf[i] == '\n')
	{
		buf = ft_strdup(buf + 1);
		free((*gnl)->bin);
		return (buf);
	}
	while (buf[i] != '\n')
		i++;
	(*gnl)->bin = buf;
	buf = ft_strdup(buf + i + 1);
	free((*gnl)->bin);
	return (buf);
}

static int			bot(t_struct **gnl, char **line, int k)
{
	if (k == 2)
	{
		(*gnl)->bin = *line;
		if (ft_strchr((*gnl)->buf2, '\n') != NULL)
		{
			*line = right((*gnl)->buf2);
			free((*gnl)->bin);
			(*gnl)->buf2 = top((*gnl)->buf2, gnl);
			return (1);
		}
		else
		{
			*line = ft_strjoin(*line, (*gnl)->buf2);
			free((*gnl)->bin);
		}
		return (2);
	}
	if (!(*gnl = ft_memalloc(sizeof(t_struct))))
		return (0);
	if (!((*gnl)->buf1 = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	(*gnl)->buf2 = NULL;
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static t_struct		*gnl = NULL;
	int					rd;

	if (!gnl)
		bot(&gnl, line, 3);
	*line = (char *)ft_memalloc(1);
	if (gnl->k && gnl->buf2)
		if ((rd = bot(&gnl, line, 2)) == 1)
			return (1);
	rd = 1;
	while ((rd = read(fd, gnl->buf1, BUFF_SIZE) > 0))
	{
		if (rd == -1)
			return (-1);
		gnl->buf1[ft_strlen(gnl->buf1)] = '\0';
		if ((gnl->buf2 = ft_strchr(gnl->buf1, '\n')) != NULL)
		{
			rd = 0;
			gnl->bin = *line;
			*line = ft_strjoin(*line, left(gnl->buf1, &gnl->buf2));
			free(gnl->bin);
			gnl->k = 1;
			return (1);
		}
		gnl->bin = *line;
		*line = ft_strjoin(*line, gnl->buf1);
		ft_bzero(gnl->buf1, ft_strlen(gnl->buf1));
		free(gnl->bin);
	}
	if (rd == 0)
		return (0);
	if (ft_strlen(*line) > 0 && rd < BUFF_SIZE)
		return (1);
	return (0);
}
