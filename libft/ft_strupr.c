/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:35:11 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 16:47:09 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupr(char *str)
{
	char	*result;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	result = (char*)malloc(sizeof(char) * ft_strlen(str));
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			result[i] = ft_toupper(str[i]);
		else
			result[i] = str[i];
		i++;
	}
	return (result);
}
