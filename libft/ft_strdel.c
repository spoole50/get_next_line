/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:17:29 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:21:19 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strdel
**	Takes as a parameter the address of a string that need to be
**	freed, then sets its pointer to NULL.
*/

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	free(*as);
	*as = NULL;
}
