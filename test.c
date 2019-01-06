/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:28:56 by spoole            #+#    #+#             */
/*   Updated: 2018/12/20 15:03:23 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;
	int		i;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	i = strcmp(line, "abcdefghijklmnop") == 0;
	get_next_line(p[0], &line);
	i = strcmp(line, "qrstuvwxyzabcdef") == 0;
	ret = get_next_line(p[0], &line);
	/*char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;
	int		i;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	i = strcmp(line, "abcdefghijklmnop") == 0;
	ret = get_next_line(p[0], &line);
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		i;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefgh\n", 9);
	write(fd, "ijklmnop\n", 9);
	write(fd, "qrstuvwx\n", 9);
	write(fd, "yzabcdef\n", 9);
	write(fd, "ghijklmn\n", 9);
	write(fd, "opqrstuv\n", 9);
	write(fd, "wxyzabcd\n", 9);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	i = (strcmp(line, "abcdefgh") == 0);
	printf("i:%d, %s\n", i, line);
	get_next_line(p[0], &line);
	i = (strcmp(line, "ijklmnop") == 0);
	printf("i:%d, %s\n", i, line);
	get_next_line(p[0], &line);
	i = (strcmp(line, "qrstuvwx") == 0);
	printf("i:%d, %s\n", i, line);
	get_next_line(p[0], &line);
	i = (strcmp(line, "yzabcdef") == 0);
	printf("i:%d, %s\n", i, line);
	get_next_line(p[0], &line);
	i = (strcmp(line, "ghijklmn") == 0);
	printf("i:%d, %s\n", i, line);
	get_next_line(p[0], &line);
	i = (strcmp(line, "opqrstuv") == 0);
	printf("i:%d, %s\n", i, line);
	get_next_line(p[0], &line);
	i = strcmp(line, "wxyzabcd") == 0;
	printf("i:%d, %s last\n", i, line);

	int fd1 = open("./test08", O_RDONLY);
	int fd2 = open("./test3.txt", O_RDONLY);
	int fd3 = open("./test.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	char **result = (char**)malloc(sizeof(char*) * 50);
	char **search = result;
	int l = 1;
	int q = 1;
	int c = 1;
	while (l == 1)
	{
		if (l != 0)
		{	
			i++;
			l = get_next_line(fd, result++);
		}
		if (q != 0)
			q = get_next_line(fd2, result++);
		if (c != 0)
			c = get_next_line(fd3, result++);
	}
	*result = 0;
	i = 0;
	while (*search != NULL)
	{
		printf("%d: %s\n", i, *search);
		search++;
	}
	if (l != 0)
		return (-1);
	else
		return (0);*/
	return (0);
}
