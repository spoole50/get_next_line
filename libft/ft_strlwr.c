/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlwr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:44:01 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 16:46:59 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlwr(char *str)
{
	char	*result;
	int		i;

	i = 0;
	result = (char*)malloc(sizeof(char) * ft_strlen(str));
	if (!str || !result)
		return (NULL);
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			result[i] = ft_tolower(str[i]);
		else
			result[i] = str[i];
		i++;
	}
	return (result);
}
