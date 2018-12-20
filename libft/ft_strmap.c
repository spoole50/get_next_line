/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:38:27 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:23:49 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strmap
**	Applies the function f to each character of the string given
**	as argument to create a “fresh” new string resulting from
**	the successive applications of f.
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*sc;
	char	*result;
	int		i;

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
			result[i] = f(sc[i]);
			i++;
		}
		result[i] = '\0';
		return (result);
	}
}
