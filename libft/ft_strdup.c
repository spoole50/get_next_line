/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:59:24 by spoole            #+#    #+#             */
/*   Updated: 2018/12/13 13:29:17 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strdup
**	Allocates memory in order to duplicate string (char *s1)
**	copies all characters from s1, adds null termiantion, and
**	returns pointer to \"fresh\" string
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *cpy;
	char *start;

	if ((cpy = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	start = cpy;
	while (*s1)
	{
		*cpy = *s1;
		s1++;
		cpy++;
	}
	*cpy = '\0';
	return (start);
}
