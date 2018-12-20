/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:34:07 by spoole            #+#    #+#             */
/*   Updated: 2018/12/20 12:25:35 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	*ft_gnl_strjoin(char *s1)
{
	char	*result;
	int		i;

	i = 0;
	result = (char*)malloc(sizeof(char) * (BUFF_SIZE + ft_strlen(s1) + 1));
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i + BUFF_SIZE] = '\0';
	return (result);
}

int		nextline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*temp;
	int			check;
	int			x;

	check = 0;
	if (temp != NULL)
		temp = ft_gnl_strjoin(temp);
	else
	{
		temp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
		temp[BUFF_SIZE] = '\0';
	}
	if (temp == NULL)
		return (-1);
	while (check == 0)
	{
		x = read(fd, temp, BUFF_SIZE);
		check = nextline(temp);
		if (check != 0)
		{
			*line = ft_strsub(temp, 0, check);
			temp = ft_strsub(temp, check + 1, ft_strlen(temp));
		}
		else
		{
			temp = ft_gnl_strjoin(temp);
		}
	}
	return (check);
}
