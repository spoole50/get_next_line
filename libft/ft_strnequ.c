/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:34:01 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:26:34 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strnequ
**	Lexicographical comparison between s1 and s2 up to n characters
**	or until a ’\0’ is reached. If the 2 strings are identical,
**	the function returns 1, or 0 otherwise.
*/

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*s1c;
	char	*s2c;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	s1c = (char*)s1;
	s2c = (char*)s2;
	i = 0;
	while (*s1c == *s2c && ++i < n)
	{
		if (*s1c == '\0')
			return (1);
		s1c++;
		s2c++;
	}
	if (*s1c == *s2c || n == 0)
		return (1);
	else
		return (0);
}
