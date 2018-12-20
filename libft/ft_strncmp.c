/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:22:53 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:15:22 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strncmp
**	Compares strings (char *s1) and (char *s2)
**	the same as strcmp but will evaluate the strings
**	only up to the (size_t n)th character.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1c;
	unsigned char	*s2c;
	size_t			x;

	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	x = 1;
	if (n == 0)
		return (0);
	while (*s1c == *s2c && x < n)
	{
		if (*s1c == '\0')
			return (0);
		s1c++;
		s2c++;
		x++;
	}
	return (*s1c - *s2c);
}
