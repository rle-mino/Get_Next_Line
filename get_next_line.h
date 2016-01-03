/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 12:59:14 by rle-mino          #+#    #+#             */
/*   Updated: 2016/01/03 10:24:16 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <stdio.h>

# define DEBUG printf("%d - %s - %s\n", __LINE__, __func__, __FILE__);
# define BUFF_SIZE 42

int					get_next_line(int const fd, char **line);

typedef struct		s_struct
{
	char			*buf1;
	char			*buf2;
	char			*bin;
	int				k;
	int				ret;
}					t_struct;

#endif
