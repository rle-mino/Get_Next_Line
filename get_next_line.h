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

# define BUFF_SIZE 30
# define DEBUG ft_putstr(__FILE__); ft_putstr(" - "); ft_putstr(__func__); ft_putstr(" - "); ft_putnbr(__LINE__); ft_putchar('\n');

int					get_next_line(int const fd, char **line);

typedef struct		s_struct
{
	char			*buf1;
	char			*buf2;
	char			*bin;
	int				k;
}					t_struct;

#endif
