/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:21:55 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:21:53 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strclr
**	Sets every character of the string to the value ’\0’.
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;

	if (s == NULL)
		return ;
	else if (*s)
	{
		i = ft_strlen(s);
		while (i-- >= 0)
			*s++ = '\0';
	}
}
