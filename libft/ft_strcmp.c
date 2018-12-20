/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:01:00 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:14:04 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strcmp
**	Compares strings (char *s1) and (char *s2)
**	if they are the same 0 is returned, otherwise
**	greater than or less than 0 if s2 is greater than
**	or less than s1.
*/

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *s1c;
	unsigned char *s2c;

	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	while (*s1c == *s2c)
	{
		if (*s1c == '\0' && *s2c == '\0')
			return (0);
		s1c++;
		s2c++;
	}
	return (*s1c - *s2c);
}
