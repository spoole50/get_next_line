/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:32:18 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:18:42 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_memalloc
**	Allocates and returns a “fresh” memory area.
**	The memory allocated is initialized to 0.
**	If the allocation fails, the function returns NULL.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*result;

	result = (void*)malloc(sizeof(void*) * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size);
	return (result);
}
