/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:13:48 by rle-mino          #+#    #+#             */
/*   Updated: 2016/01/04 15:51:09 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line = NULL;
	int		fd;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	fd = 42;
	//fd = open(argv[1], O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		//printf("%d\t%s\n", ++i ,line);
		//free(line);
	}
	printf("%d\n", i);
	close(fd);
	return (0);
}
