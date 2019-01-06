/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ll.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:45:21 by spoole            #+#    #+#             */
/*   Updated: 2019/01/06 13:45:05 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_
# define _GET_NEXT_LINE_
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define MAX_FD 256
# define BUFF_SIZE 100

int		get_next_line(const int fd, char **line);

typedef	struct			s_gnl
{
	struct s_gnl		*next;
	char				*data;
	char				*clean;
	int					fd;
	int					i;
}						t_gnl;

#endif
