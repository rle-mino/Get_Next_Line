/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:06:35 by rle-mino          #+#    #+#             */
/*   Updated: 2016/01/08 20:12:08 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*fill_line(char *line, char *buf)
{
	char	*tmp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	tmp = line;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!line)
		line = ft_memalloc(i + 1);
	else
		line = ft_memalloc(i + ft_strlen(tmp) + 1);
	i = 0;
	while (tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	while (buf[j] && buf[j] != '\n')
	{
		line[i] = buf[j];
		i++;
		j++;
	}
	free(tmp);
	return (line);
}

int		malloker(t_struct **gnl)
{
	if (!(*gnl = (t_struct *)ft_memalloc(sizeof(t_struct) + 1)))
		return (0);
	if (!((*gnl)->buf1 = ft_memalloc(BUFF_SIZE + 1)))
		return (0);
	(*gnl)->buf2 = NULL;
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	t_struct		*gnl = NULL;
	int				rd;

	if (!gnl)
		malloker(&gnl);
	*line = (char *)ft_memalloc(1);
	while (gnl->buf2 || (rd = read(fd, gnl->buf1, BUFF_SIZE)))
	{
		/*if (gnl->buf2)
		{
			*line = fill_line(*line, gnl->buf2 + 1);
			if ((gnl->buf2 = ft_strchr(gnl->buf2 + 1, '\n')))
				return (1);
			rd = read(fd, gnl->buf1, BUFF_SIZE);
		}*/
		if (rd < 0)
			return (-1);
		if ((gnl->buf2 = ft_strchr(gnl->buf1, '\n')))
		{
			*line = fill_line(*line, gnl->buf1);
			return (1);
		}
		*line = fill_line(*line, gnl->buf1);
	}
	if (rd == 0 && ft_strlen(*line) > 0)
		return (1);
	return (0);
}
