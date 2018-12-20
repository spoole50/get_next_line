/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:29:36 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:25:52 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	ft_strequ
**	Lexicographical comparison between s1 and s2. If the 2
**	strings are identical the function returns 1, or 0 otherwise.
*/

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char	*s1c;
	char	*s2c;

	if (s1 == NULL || s2 == NULL)
		return (0);
	s1c = (char*)s1;
	s2c = (char*)s2;
	while (*s1++ == *s2++)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (1);
	}
	return (0);
}
