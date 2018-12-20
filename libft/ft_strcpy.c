/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:01:25 by spoole            #+#    #+#             */
/*   Updated: 2018/12/13 13:31:16 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strcpy
**	Copies string from (char *src) to (char *dest)
**	adds NULL termination and returns dest string.
*/

char	*ft_strcpy(char *dest, char *src)
{
	char *begin;

	begin = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (begin);
}
