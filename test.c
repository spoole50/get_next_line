/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:28:56 by spoole            #+#    #+#             */
/*   Updated: 2018/12/19 19:41:17 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int fd = open("./test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	char **result = (char**)malloc(sizeof(char*) * 50);
	int l = 1;
	while (l > 0)
	{
		l = get_next_line(fd, result++);
	}
	*result = 0;
	if (l != 0)
		return (1);
	else
		return (0);
}
