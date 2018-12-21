/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:35:10 by spoole            #+#    #+#             */
/*   Updated: 2018/12/20 15:18:27 by spoole           ###   ########.fr       */
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
#endif
