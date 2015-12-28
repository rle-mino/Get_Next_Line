/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 12:59:14 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/27 14:41:04 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>
#define DEBUG printf("%d - %s - %s\n", __LINE__, __func__, __FILE__);
#define BUFF_SIZE 32

int		get_next_line(int const fd, char **line);

typedef struct		s_struct
{
	char			*buf1;
	char			*buf2;
	char			*tmp;
}					t_struct;

#endif
