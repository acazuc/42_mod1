/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:06:54 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 10:13:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					get_next_line(const int fd, char **line);

typedef struct		s_gnl
{
	char			**line;
	char			**start;
	char			**buffer;
	int				fd;
}					t_gnl;

#endif
