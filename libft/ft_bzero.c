/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:03:47 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 12:29:03 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_bzero
**	Utilizing the ft_memset function, sets (size_t n) bytes
**	to zero ('0') at memory location (void *s).
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
