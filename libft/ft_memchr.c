/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:27:40 by spoole            #+#    #+#             */
/*   Updated: 2018/12/13 13:02:03 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_memchr
**	locates first instance of (int c) within (size_t n)
**	bytes of string (void *s). Returns pointer to located
**	byte or NULL if c doesnt exist within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			x;

	x = -1;
	temp = (unsigned char*)s;
	while (++x < n)
	{
		if (temp[x] == (unsigned char)c)
			return (temp + x);
	}
	return (NULL);
}
