/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:34:07 by spoole            #+#    #+#             */
/*   Updated: 2018/12/20 15:10:49 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strjoin(char *s1)
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

char	*init_temp(char *temp, int *i)
{
	if (temp != NULL)
		temp = ft_gnl_strjoin(temp);
	else
	{
		temp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
		temp[BUFF_SIZE] = '\0';
		*i = 0;
	}
	return (temp);
}

char	*handle_newline(char *temp, char **line, int check, int *i)
{
	*line = ft_strsub(temp, 0, check);
	temp = ft_strsub(temp, check + 1, ft_strlen(temp + check));
	*i = ft_strlen(temp);
	return (temp);
}

int		get_next_line(const int fd, char **line)
{
	static char	*temp;
	static int	i;
	int			check;
	int			x;

	check = 0;
	temp = init_temp(temp, &i);
	if (temp == NULL)
		return (-1);
	while (check == 0)
	{
		x = read(fd, &temp[i], BUFF_SIZE);
		i += BUFF_SIZE;
		check = nextline(temp);
		if (x == 0)
		{
			while (nextline(temp) != 0)
				temp = handle_newline(temp, line++, check, &i);
			*line = temp;
			return (0);
		}
		else if (check != 0)
			temp = handle_newline(temp, line, check, &i);
		else
			temp = ft_gnl_strjoin(temp);
	}
	return (1);
}
