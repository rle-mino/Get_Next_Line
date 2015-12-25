/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:06:35 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/25 19:08:21 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char		*left(char *buf, char *sla)
{
	char	*left;
	int		i;

	i = ft_strlen(buf) - ft_strlen(sla);
	left = ft_strsub(buf, 0, i);
	return (left);
}

void					pupute(int *rd, t_struct *ko, char **line)
{
	ko->buf1[BUFF_SIZE - 1] = '\0';
	if ((ko->buf2 = ft_strchr(ko->buf1, '\n')) != NULL)
	{
		*line = ft_strjoin(*line, left(ko->buf1, ko->buf2));
		*rd = 0;
		ko->buf2++;
	}
	else
		*line = ft_strjoin(*line, ko->buf1);
}

int						get_next_line(int fd, char **line)
{
	static t_struct		*ko = NULL;
	int					rd;

	if (!(ko))
		ko = (t_struct *)ft_memalloc(sizeof(t_struct));
	ko->buf1 = ft_strnew(BUFF_SIZE);
	if (ko->buf2)
	{
		ko->buf1 = ft_strcpy(ko->buf1, ko->buf2);
		ko->k = ft_strlen(ko->buf2) - 1;
	}
	else
		ko->k = 0;
	rd = 1;
	*line = (char *)ft_strnew(BUFF_SIZE);
	while (rd > 0)
	{
		if ((ko->buf1 = ft_strchr(ko->buf1, '\n')) == NULL)
			rd = read(fd, ko->buf1 + ko->k , (BUFF_SIZE - ko->k));//retourne -1
		if (rd == 0)
			return (0);
		pupute(&rd, ko, line);
	}
	return (1);
}
