/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:27:28 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:22:26 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_striter
**	Applies the function f to each character of the string passed
**	as argument. Each character is passed by address to f to be
**	modified if necessary.
*/

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	if (s == NULL || f == NULL)
		return ;
	while (*s)
	{
		f(s);
		s++;
	}
}
