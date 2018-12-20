/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:15:48 by spoole            #+#    #+#             */
/*   Updated: 2018/12/13 13:49:54 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strncat
**	Behaves similarly to ft_strcat but will not
**	add more than (size_t n) bytes of (char *src)
**	to the end of (char *dst).
*/

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	int		i;
	size_t	x;

	x = -1;
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (*src != '\0' && ++x < n)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dst);
}
