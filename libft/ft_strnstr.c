/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:24:30 by spoole            #+#    #+#             */
/*   Updated: 2018/12/16 19:38:14 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strnstr
**	Same as strstr excpet not more than (size_t len)
**	characters are searched.
*/

#include "libft.h"

static int	mtchckn(int pos, char *hay, char *ned, int max)
{
	int	y;

	y = 0;
	while (hay[pos] != '\0' && ned[y] != '\0')
	{
		if (pos >= max)
			return (0);
		else if (hay[pos++] == ned[y])
			y++;
		else
			return (0);
	}
	if (hay[pos] == '\0' && ned[y] != '\0')
		return (0);
	else
		return (1);
}

char		*ft_strnstr(const char *hay, const char *ned, size_t len)
{
	char	*look;
	char	*find;
	int		x;

	look = (char*)hay;
	find = (char*)ned;
	x = 0;
	if (*find == '\0' || find == look)
		return (look);
	while (look[x] != '\0' && x < (int)len)
	{
		if ((look[x] == *find) && mtchckn(x, look, find, (int)len))
			return (look + x);
		x++;
	}
	return (NULL);
}
