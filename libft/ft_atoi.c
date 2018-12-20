/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:14:34 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:17:14 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_atoi
**	ASCII to INTEGER conversion function
**	string (char *str) is converted as long as
**	the string is a valid integer.
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int i;
	int x;

	sign = 1;
	result = 0;
	i = 0;
	x = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == '-')
			sign = -1;
		x++;
	}
	while (str[i + x] >= 48 && str[i + x] <= 57)
	{
		result = (result * 10) + str[i + x] - '0';
		x++;
	}
	return (result * sign);
}
