/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:56:03 by spoole            #+#    #+#             */
/*   Updated: 2018/12/15 12:03:30 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strchr
**	Locates first occurance of (int c) within string
**	(char *s) including NULL terminator. If found
**	function returns pointer to the matching character
**	otherwise NULL if the character does not appear.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	else
		return (0);
}
