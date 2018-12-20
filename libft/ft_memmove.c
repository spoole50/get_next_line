/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:29:56 by spoole            #+#    #+#             */
/*   Updated: 2018/12/12 15:44:39 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_memmove
**	Copies (size_t n) bytes from (void *dst) to (void *src)
**	returns original value of dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dstc;
	char	*srcc;
	size_t	x;

	x = -1;
	dstc = (char*)dst;
	srcc = (char*)src;
	if (srcc < dstc)
	{
		while (n > 0)
		{
			dstc[n - 1] = srcc[n - 1];
			n--;
		}
	}
	else
	{
		while (++x < n)
			dstc[x] = srcc[x];
	}
	return (dstc);
}
