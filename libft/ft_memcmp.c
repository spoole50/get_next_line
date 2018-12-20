/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:48:45 by spoole            #+#    #+#             */
/*   Updated: 2018/12/13 13:19:12 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_memcmp
**	Compares string (void *s1) to string (void *s2)
**	for (size_t n) bytes. Returns 0 if strings are identical
**	otherwise returns difference of first unmatached bytes.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1c;
	unsigned char	*s2c;
	size_t			x;

	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	x = -1;
	while (++x < n)
	{
		if (s1c[x] != s2c[x])
			return (s1c[x] - s2c[x]);
	}
	return (0);
}
