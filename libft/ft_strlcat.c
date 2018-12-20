/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:22:22 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 10:52:03 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strlcat
**	Appends string (char *src) to the end of (char *dst)
**	with (size_t dtsize) being the full size of destination buffer.
**	Will append at most dtsize - strlen(dst) - 1 characters. Will
**	NULL terminate unless dtsize is 0. Returns total length of the
**	string attempted to create (intial length of dst + strlen(src)).
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dtsize)
{
	size_t	di;
	size_t	si;

	di = 0;
	si = 0;
	if (dtsize == 0)
		return (ft_strlen(dst));
	while (dst[di] != '\0' && di < dtsize)
		di++;
	while (src[si] != '\0' && (di + si) < dtsize - 1)
	{
		dst[di + si] = src[si];
		si++;
	}
	if ((di + si) < dtsize)
		dst[di + si] = '\0';
	return (di + ft_strlen(src));
}
