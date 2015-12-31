/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:13:48 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/31 15:51:14 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%d\t%s\n", ++i, line);
		free(line);
	}
	close(fd);
}
