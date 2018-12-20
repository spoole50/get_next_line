/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:46:39 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:27:47 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strsub
**	Allocates and returns a “fresh” substring from the
**	string given as argument. The substring begins at
**	indexstart and is of size len. If start and len aren’t
**	refering to a valid substring, the behavior is undefined.
**	If the allocation fails, the function returns NULL.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*result;
	int				i;

	i = 0;
	if (s == NULL)
		return (NULL);
	result = (char*)malloc(sizeof(char) * len + 1);
	if (result != NULL)
	{
		while (s[start] != '\0' && i < (int)len)
			result[i++] = s[start++];
		result[i] = '\0';
		return (result);
	}
	else
		return (NULL);
}
