/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:16:54 by spoole            #+#    #+#             */
/*   Updated: 2018/12/01 23:58:51 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int temp;

	temp = 0;
	if (n < -2147483647)
		ft_putstr_fd("-2147483648", fd);
	else if (n > 2147483646)
		ft_putstr_fd("2147483647", fd);
	else if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n, fd);
	}
	else if ((n / 10) > 0)
	{
		temp = n;
		n /= 10;
		ft_putnbr_fd(n, fd);
		ft_putchar_fd(((temp % 10) + '0'), fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
