/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:06:35 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/20 14:13:40 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char		*buf[BUFF_SIZE];
	int				i;

	while (read(fd, buf, BUFF_SIZE) && ft_strchr(buf, '\n') == NULL)
	{
		i = 0;
		while (i < BUFF_SIZE && buf[i] != '\n')
		{
			line[i] = buf[i];
			i++;
		}
	}
	return (1);
}
