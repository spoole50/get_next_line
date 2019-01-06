/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:45:21 by spoole            #+#    #+#             */
/*   Updated: 2019/01/05 20:18:32 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*initialize_fd(int fd, t_gnl *begin)
{
	t_gnl	*result;

	result = (t_gnl*)malloc(sizeof(t_gnl));
	result->next = NULL;
	result->data = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(result->data, BUFF_SIZE + 1);
	result->fd = fd;
	result->i = read(fd, &result->data[0], BUFF_SIZE);
	if (begin != NULL)
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = result;
	}
	return (result);
}

char	*read_to_nl(t_gnl *temp)
{
	int		i;
	int		c;
	int		x;
	char	*clean;
	char	*result;

	i = 0;
	c = 1;
	result = NULL;
	clean = NULL;
	while (c == 1)
	{
		x = temp->i;
		while (temp->data[i] != '\0' && temp->data[i] != '\n')
			i++;
		if (temp->data[i] == '\0' && temp->i != 0)
		{
			//temp->data = ft_gnl_strjoin(temp->data);
			temp->data = ft_strbuf(temp->data, BUFF_SIZE);
			x = read(temp->fd, &temp->data[i], BUFF_SIZE);
			if (x != 0)
				temp->i += x;
			else
				temp->i = 0;
		}
		else
		{
			clean = temp->data;
			result = ft_strsub(temp->data, 0, i);
			if (temp->data[i] == '\n')
			{
				temp->i -= ft_strlen(result);
				temp->data = ft_strsub(temp->data, i + 1, ft_strlen(temp->data));
			}
			else
				temp->data = NULL;
			free(clean);
			c = 0;
		}
	}
	return (result);
}

int		get_next_line(const int fd, char **line)
{
	static	t_gnl	*begin;
	t_gnl			*temp;
	t_gnl			*clean;
	char			*result;

	clean = NULL;
	temp = begin;
	result = NULL;
	if (fd < 0 || line == NULL)
		return (-1);
	if (temp != NULL)
	{
		while (temp != NULL && temp->fd != fd)
			temp = temp->next;
	}
	else if (temp == NULL)
	{
		temp = initialize_fd(fd, begin);
		if (temp->i < 0)
			return (-1);
		else if (begin == NULL)
			begin = temp;
	}
	if (temp->i != 0)
	{
		result = read_to_nl(temp);
		if (*result != '\0')
			*line = result;
	}
	if (temp->i == 0 && (result == NULL || *result == '\0'))
	{
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
		return (0);
	}
	return (1);
}
