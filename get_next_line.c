/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:06:35 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/28 12:55:56 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char			*left(char *buf1, char **buf2)
{
	size_t			i;

	*buf2 = ft_strdup(*buf2);
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

char			*mouvep(char **str)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = *str;
	while (*str[i] != '\n' && *str[i])
		i++;
	i++;
	*str = *str + i;
	return (tmp);
}

int				get_next_line(int const fd, char **line)
{
	static t_struct		*ko = NULL;
	int					rd;

	if (!ko)
	{
		ko = (t_struct *)malloc(sizeof(t_struct));
		ko->buf1 = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	}
	*line = (char *)malloc(1);
	if (ko->buf2)
	{
		if (ft_strchr(ko->buf2, '\n') != NULL)
		{
			*line = ft_strjoin(*line, mouvep(&ko->buf2));
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
			return (1);
		}
		*line = ft_strjoin(*line, ko->buf1);
	}
	return (0);
}
