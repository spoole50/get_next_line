/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:08:42 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:32:01 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_itoa
**	Allocate and returns a “fresh” string ending with ’\0’
**	representing the integer n given as argument.
**	Negative numbers must be supported. If the allocation
**	fails, the function returns NULL.
*/

#include "libft.h"

static int		make_arr(int n, char **result)
{
	int		i;

	i = 0;
	if (n == -2147483648)
		i = 11;
	else
	{
		if (n < 0)
		{
			n *= -1;
			i += 1;
		}
		while ((n / 10) > 0)
		{
			n /= 10;
			i += 1;
		}
	}
	i++;
	*result = (char*)malloc(sizeof(char) * i + 1);
	return (i);
}

static void		int_min(char *result)
{
	char	*min;
	int		i;

	i = 0;
	min = "-2147483648";
	while (min[i])
	{
		result[i] = min[i];
		i++;
	}
	result[i] = '\0';
}

static void		work(int n, int size, char *result)
{
	int		i;
	int		neg;

	i = 1;
	neg = 0;
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
		neg = 1;
	}
	while ((size - i) > 0)
	{
		result[size - i++] = (n % 10) + '0';
		n /= 10;
	}
	if (neg == 0)
		result[size - i] = n + '0';
	result[size] = '\0';
}

char			*ft_itoa(int n)
{
	int		size;
	char	*result;

	result = NULL;
	if (n > 2147483647 || n < -2147483648)
		return (NULL);
	size = make_arr(n, &result);
	if (result == NULL)
		return (NULL);
	if (n == -2147483648)
		int_min(result);
	else
		work(n, size, result);
	return (result);
}
