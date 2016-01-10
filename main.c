/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:47:06 by rle-mino          #+#    #+#             */
/*   Updated: 2016/01/08 19:52:50 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_Line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		k;

	k = 0;
	i = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while ((k = get_next_line(fd, &line) > 0))
	{
		printf("gnl value = %d", k);
		printf("\t%d\t%s\n", ++i, line);
		free(line);
	}
	close(fd);
}
