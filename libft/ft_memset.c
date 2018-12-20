/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:02:07 by spoole            #+#    #+#             */
/*   Updated: 2018/12/12 15:30:49 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_memset
**	Writes (int c) for length (size_t len) at memory address (void *in).
*/

#include "libft.h"

void	*ft_memset(void *in, int c, size_t len)
{
	int		i;
	void	*out;

	i = 0;
	out = in;
	while (i < (int)len)
	{
		*((unsigned char*)in) = c;
		in++;
		i++;
	}
	return (out);
}
