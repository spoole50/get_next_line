/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:17:18 by spoole            #+#    #+#             */
/*   Updated: 2018/12/12 15:37:51 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_memccpy
**	Copies bytes from address (void *src) to address (void *dst),
**	if (int c) is found write is terminated and the byte after
**	the instance of c is returned. Otherwise, (size_t n) bytes
**	are copied and NULL is returned.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	s;

	s = (unsigned char)c;
	i = 0;
	while (i < (int)n)
	{
		*((unsigned char*)dst) = *((unsigned char*)src);
		if (*(unsigned char*)src == s)
			return (++dst);
		i++;
		dst++;
		src++;
	}
	return (NULL);
}
