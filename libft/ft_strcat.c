/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:04:10 by spoole            #+#    #+#             */
/*   Updated: 2018/12/13 13:46:24 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strcat
**	Adds (conCATenates) copy of (char *src) to the end of
**	(char *dst) then adds NULL termination.
*/

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (dst[i] != '\0')
		i++;
	while (*src != '\0')
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dst);
}
