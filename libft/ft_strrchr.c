/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:20:01 by spoole            #+#    #+#             */
/*   Updated: 2018/12/15 12:06:20 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strrchr
**	Identical to strchr function except this function
**	locates the LAST occuenace of (int c).
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char cc;
	char *result;

	cc = (char)c;
	result = NULL;
	while (*s != '\0')
	{
		if (*s == cc)
			result = (char*)s;
		s++;
	}
	if (cc == '\0')
		return (result = (char*)s);
	else
		return (result);
}
