/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:31:11 by spoole            #+#    #+#             */
/*   Updated: 2018/12/16 16:29:17 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*result;
	size_t	extra;
	void	*temp;

	extra = 0;
	if (content != NULL && content_size > 0)
		extra = content_size;
	result = (t_list*)malloc(sizeof(t_list) * 1);
	if (result == NULL)
		return (NULL);
	if (extra == 0)
	{
		result->content = NULL;
		result->content_size = extra;
	}
	else
	{
		temp = (void*)malloc(sizeof(unsigned char) * extra);
		if (temp == NULL)
			return (NULL);
		result->content = ft_memcpy(temp, (void*)content, extra);
		result->content_size = extra;
	}
	result->next = NULL;
	return (result);
}
