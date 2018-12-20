/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:53:56 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:10:49 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strstr
**	Locates the first instnace of string (char *ned)
**	within string (char *hay). If ned is empty hay
**	is returned. If ned is not found in hay NULL is
**	returned. Otherwise a pointer to the first character
**	of ned within the hay string is returned.
*/

#include "libft.h"

static int	mtchck(int pos, char *hay, char *ned)
{
	int y;

	y = 0;
	while (hay[pos] != '\0' && ned[y] != '\0')
	{
		if (hay[pos++] == ned[y])
			y++;
		else
			return (0);
	}
	if (hay[pos] == '\0' && ned[y] != '\0')
		return (0);
	else
		return (1);
}

char		*ft_strstr(const char *hay, const char *ned)
{
	char	*look;
	char	*find;
	int		x;

	look = (char*)hay;
	find = (char*)ned;
	x = 0;
	if (*find == '\0')
		return (look);
	while (look[x] != '\0')
	{
		if ((look[x] == *find) && mtchck(x, look, find))
			return (look + x);
		x++;
	}
	return (NULL);
}
