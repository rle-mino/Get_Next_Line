/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_td.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:56:59 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/20 12:32:05 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_free_td(char **str, int d2)
{
	int		j;

	j = 0;
	if (str == NULL)
		return ;
	while (j < d2)
	{
		free(str[j]);
		j++;
	}
	free(str);
}