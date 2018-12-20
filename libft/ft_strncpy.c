/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:58:02 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 11:14:53 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strncpy
**	Copies at most (size_t len) charcters from (char *src)
**	to (char *dest). If src is less than len characters
**	dest is filled with '\0'. Otherwise dest is not terminated.
*/

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, size_t len)
{
	int		i;

	i = 0;
	while (src[i] && i < (int)len)
	{
		dest[i] = src[i];
		if (i >= (int)len - 1)
			return (dest);
		i++;
	}
	while (i < (int)len - 1)
		dest[i++] = (char)NULL;
	if (i < (int)len)
		dest[i] = '\0';
	return (dest);
}
