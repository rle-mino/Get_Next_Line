/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:06:35 by rle-mino          #+#    #+#             */
/*   Updated: 2016/01/10 15:58:42 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char			*fill_line(char *line, char *buf)
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
	i = -1;
	while (tmp[++i])
		line[i] = tmp[i];
	while (buf[j] && buf[j] != '\n')
	{
		line[i] = buf[j];
		i++;
		j++;
	}
	free(tmp);
	return (line);
}

void			multi_fd(t_struct **gnl, int fd)
{
	t_struct	*tmp;

	while ((*gnl)->prev != NULL && (*gnl)->fd != fd)
		*gnl = (*gnl)->prev;
	while ((*gnl)->next != NULL && (*gnl)->fd != fd)
		*gnl = (*gnl)->next;
	if ((*gnl)->fd != fd)
	{
		tmp = *gnl;
		(*gnl)->next = ft_memalloc(sizeof(t_struct) + 1);
		*gnl = (*gnl)->next;
		(*gnl)->b1 = ft_memalloc(BUFF_SIZE + 1);
		(*gnl)->b2 = NULL;
		(*gnl)->next = NULL;
		(*gnl)->prev = tmp;
		(*gnl)->fd = fd;
	}
}

static int		malloker(t_struct **gnl, char **line, int fd)
{
	*line = ft_memalloc(1);
	if (!*gnl)
	{
		if (!(*gnl = (t_struct *)ft_memalloc(sizeof(t_struct) + 1)))
			return (0);
		if (!((*gnl)->b1 = ft_memalloc(BUFF_SIZE + 1)))
			return (0);
		(*gnl)->b2 = NULL;
		(*gnl)->fd = fd;
		(*gnl)->next = NULL;
		(*gnl)->prev = NULL;
		return (1);
	}
	if ((*gnl)->fd != fd)
		multi_fd(gnl, fd);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_struct		*gnl = NULL;
	int					rd;

	if (fd < 0 || line == NULL)
		return (-1);
	malloker(&gnl, line, fd);
	while (gnl->b2 || (rd = read(fd, gnl->b1, BUFF_SIZE)))
	{
		if (gnl->b2)
		{
			*line = fill_line(*line, gnl->b2 + 1);
			if ((gnl->b2 = ft_strchr(gnl->b2 + 1, '\n')) != NULL)
				return (1);
			if (!(rd = read(fd, gnl->b1, BUFF_SIZE)))
				return (0);
		}
		if (rd < 0)
			return (-1);
		gnl->b1[rd] = '\0';
		*line = fill_line(*line, gnl->b1);
		if ((gnl->b2 = ft_strchr(gnl->b1, '\n')))
			return (1);
	}
	return ((rd || **line) ? 1 : 0);
}
