/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:50:26 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:24:59 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strmapi
** Applies the function f to each character of the string passed
**	as argument by giving its index as first argument to create a
**	“fresh” new string resulting from the successive applications of f.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*sc;
	char			*result;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	sc = (char*)s;
	result = (char*)malloc(ft_strlen(s) + 1);
	if (result == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (sc[i])
		{
			result[i] = f(i, sc[i]);
			i++;
		}
		result[i] = '\0';
		return (result);
	}
}
