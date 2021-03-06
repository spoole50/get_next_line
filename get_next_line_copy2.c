/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:34:07 by spoole            #+#    #+#             */
/*   Updated: 2019/01/02 20:02:03 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*init_temp(char *temp, int *i, int *x)
{
	if (temp != NULL)
		temp = ft_gnl_strjoin(temp);
	else
	{
		temp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
		temp[BUFF_SIZE] = '\0';
		*i = 0;
		*x = 1;
	}
	return (temp);
}

char	*handle_newline(char *temp, char **line, int check, int *i)
{
	char	*clean;
	clean = temp;
	*line = ft_strsub(temp, 0, check);
	temp = ft_strsub(temp, check + 1, ft_strlen(temp + check));
	free(clean);
	*i = ft_strlen(temp);
	return (temp);
}

int		get_next_line(const int fd, char **line)
{
	static char	*temp;
	static int	i;
	int			x;
	int			check;

	check = 0;
	temp = init_temp(temp, &i, &x);
	if (temp == NULL)
		return (-1);
	while (check == 0)
	{
		x = read(fd, &temp[i], BUFF_SIZE);
		if (x != 0)
			i += BUFF_SIZE;
		check = nextline(temp);
		if (x == 0)
		{
			if (check != 0)
			{
				temp = handle_newline(temp, line++, check, &i);
				return (1);
			}
			else
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
