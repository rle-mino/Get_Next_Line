/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:52:51 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/14 17:57:04 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (cpy == NULL)
		return (NULL);
	while (i <= ft_strlen(s1))
	{
		cpy[i] = s1[i];
		i++;
	}
	return (cpy);
}
