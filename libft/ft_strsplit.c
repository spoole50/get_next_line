/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:08:20 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:31:06 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strsplit
**	Allocates and returns an array of “fresh” strings
**	(all ending with ’\0’, including the array itself)
**	obtained by spliting s using the character c as a
**	delimiter. If the allocation fails the function returns NULL.
*/

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	char	**result;
	size_t	i;
	size_t	x;
	size_t	len;

	if (!s || !c || !(result = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while ((s[i + len] != '\0') && (s[i + len] != c))
				len++;
			result[x++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	result[x] = 0;
	return (result);
}
