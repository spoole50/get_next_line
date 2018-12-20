/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:04:31 by spoole            #+#    #+#             */
/*   Updated: 2018/12/12 15:30:31 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_memcpy
**	Writes (size_t n) data from address (void *src) to address (void *dst).
*/

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	void	*ret;
	int		i;

	ret = dst;
	i = 0;
	while (i++ < (int)n)
	{
		*((unsigned char*)dst) = *((unsigned char*)src);
		dst++;
		src++;
	}
	return (ret);
}
