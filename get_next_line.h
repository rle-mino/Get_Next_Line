/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 12:59:14 by rle-mino          #+#    #+#             */
/*   Updated: 2016/01/09 11:11:18 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 32

int						get_next_line(int const fd, char **line);

typedef struct			s_struct
{
	char				*b1;
	char				*b2;
	int					fd;
	struct s_struct		*next;
	struct s_struct		*prev;
}						t_struct;

#endif
