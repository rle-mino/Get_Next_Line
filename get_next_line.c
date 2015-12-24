/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:06:35 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/24 12:15:18 by rle-mino         ###   ########.fr       */
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

char					*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(s3 = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		s3[k] = s1[i];
		i++;
		k++;
	}
	i = 0;
	while (s2[i])
	{
		s3[k] = s2[i];
		k++;
		i++;
	}
	free(s1);
	return (s3);
}

void					pupute(int rd, t_struct *ko, char *k, char **line)
{
	ko->buf1[BUFF_SIZE] = '\0';
	if ((k = ft_strchr(ko->buf1, '\n')) != NULL)
	{
		*line = ft_strjoin_gnl(*line, left(ko->buf1, k));
		rd = 0;
	}
	else
		*line = ft_strjoin_gnl(*line, ko->buf1);
}

int						get_next_line(int fd, char **line)
{
	static t_struct		*ko = NULL;
	int					rd;
	char				*k;

	if (!(ko))
		ko = (t_struct *)ft_memalloc(sizeof(t_struct));
	ko->buf1 = (char *)ft_memalloc(BUFF_SIZE + 1);
	rd = 1;
	*line = (char *)ft_memalloc(BUFF_SIZE + 1);
	while (rd > 0)
	{
		DEBUG;
		rd = read(fd, ko->buf1, BUFF_SIZE);
		pupute(rd, ko, k, line);
	}
	//ko->buf2 = ft_strdup(k);
	printf("%s\n", *line);
	free(ko->buf1);
	return (1);
}
