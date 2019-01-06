/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:45:21 by spoole            #+#    #+#             */
/*   Updated: 2019/01/06 13:45:05 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*initialize_fd(int fd, t_gnl *begin)
{
	t_gnl	*result;

	result = begin;
	if (result != NULL)
	{
		while (result != NULL && result->fd != fd)
			result = result->next;
	}
	if (result == NULL)
	{
		result = (t_gnl*)malloc(sizeof(t_gnl));
		result->next = NULL;
		result->data = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		ft_bzero(result->data, BUFF_SIZE + 1);
		result->fd = fd;
		result->clean = NULL;
		result->i = read(fd, &result->data[0], BUFF_SIZE);
		if (begin != NULL)
		{
			while (begin->next != NULL)
				begin = begin->next;
			begin->next = result;
		}
	}
	return (result);
}

char	*read_fd(t_gnl *temp, char *result, int c, int q)
{
	int	x;

	if (q == 1)
	{
		x = temp->i;
		temp->data = ft_strbuf(temp->data, BUFF_SIZE);
		x = read(temp->fd, &temp->data[c], BUFF_SIZE);
		if (x != 0)
			temp->i += x;
		else
			temp->i = 0;
	}
	else if (q == 2)
	{
		result = ft_strsub(temp->data, 0, c);
		if (temp->data[c] == '\n')
		{
			temp->i -= ft_strlen(result);
			temp->data = ft_strsub(temp->data,
			c + 1, ft_strlen(temp->data));
		}
		else
			temp->data = NULL;
	}
	return (result);
}

char	*read_to_nl(t_gnl *temp)
{
	int		c;
	int		x;
	char	*result;

	c = 0;
	result = NULL;
	while (c >= 0)
	{
		x = temp->i;
		while (temp->data[c] != '\0' && temp->data[c] != '\n')
			c++;
		if (temp->data[c] == '\0' && temp->i != 0)
			read_fd(temp, result, c, 1);
		else
		{
			temp->clean = temp->data;
			result = read_fd(temp, result, c, 2);
			free(temp->clean);
			temp->clean = NULL;
			c = -1;
		}
	}
	return (result);
}

void	close_gnl(t_gnl *begin, t_gnl *temp)
{
	t_gnl	*clean;

	clean = NULL;
	if (temp == begin)
		begin = temp->next;
	else
	{
		clean = begin;
		while (clean->next != temp)
			clean = clean->next;
		clean->next = temp->next;
	}
	free(temp);
}

int		get_next_line(const int fd, char **line)
{
	static	t_gnl	*begin;
	t_gnl			*temp;
	char			*result;

	temp = NULL;
	result = NULL;
	if (fd < 0 || line == NULL)
		return (-1);
	temp = initialize_fd(fd, begin);
	if (temp->i < 0)
		return (-1);
	else if (begin == NULL)
		begin = temp;
	if (temp->i != 0)
	{
		result = read_to_nl(temp);
		if (*result != '\0' || temp->i > 0)
			*line = result;
	}
	if (temp->i == 0 && (result == NULL || *result == '\0'))
	{
		close_gnl(begin, temp);
		return (0);
	}
	return (1);
}
