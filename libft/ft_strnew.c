/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:59:22 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:20:38 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strnew
**	Allocates and returns a “fresh” string ending
**	with ’\0’. Each character of the string is initialized at
**	’\0’. If the allocation fails the function returns NULL.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if ((result = (char*)malloc(sizeof(char) * size + 1)))
	{
		while (i <= size)
			result[i++] = '\0';
		return (result);
	}
	else
		return (NULL);
}
