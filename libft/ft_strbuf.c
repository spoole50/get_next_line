/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:52:53 by spoole            #+#    #+#             */
/*   Updated: 2019/01/06 12:56:49 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_strbuf
**  Allocates and returns "fresh" string consisting of
**  (char *s1) and additonal memory padding of size (size_t pad).
**  Fresh memory set to all zeros before s1 is copied in. Frees s1
**  memory location.
*/

char	*ft_strbuf(char *s1, size_t pad)
{
	char	*result;
	int		i;
	int		x;

	result = NULL;
	i = 0;
	x = pad + ft_strlen(s1) + 1;
	result = (char*)malloc(sizeof(char) * x);
	ft_bzero(result, x);
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	free(s1);
	return (result);
}
