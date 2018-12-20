/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:31:13 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:30:01 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strtrim
**	Allocates and returns a copy of the string given as
** 	argument without whitespaces at the beginning or at
**	the end of the string. Will be considered as whitespaces
**	the	following characters ’ ’, ’\n’ and ’\t’. If s has
**	no whitespaces at the beginning or at the end, the function
**	returns a copy of s. If the allocation fails the function returns NULL.
*/

#include "libft.h"

static int	calc_space(char *s)
{
	int	i;
	int x;

	i = 0;
	x = 0;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i++] != '\0')
		x++;
	i -= 2;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		x--;
	}
	if (i <= 0 || x <= 0)
		return (1);
	else
		return (x);
}

char		*ft_strtrim(char const *s)
{
	char	*result;
	char	*res_start;
	char	*trm;
	int		i;
	int		size;

	trm = (char*)s;
	if (trm == NULL)
		return (NULL);
	i = 0;
	size = calc_space(trm);
	result = (char*)malloc(sizeof(char) * (size + 1));
	if (result != NULL)
	{
		res_start = result;
		while (*trm == 32 || *trm == '\n' || *trm == '\t')
			trm++;
		while (i++ < size)
			*result++ = *trm++;
		*result = '\0';
		return (res_start);
	}
	else
		return (NULL);
}
