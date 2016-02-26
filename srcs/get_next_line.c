/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 08:51:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 10:13:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static int	get_eol(char *data)
{
	size_t			i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	get_next_line_main_part(t_gnl *e, char *buffer, long eol_i
		, int readed)
{
	if (eol_i != -1)
	{
		if (!(*(e->line) = ft_strjoin_free3(*(e->line)
						, ft_strsub(buffer, 0, eol_i))))
			return (-1);
		*(e->start) = ft_strsub(buffer, eol_i + 1, readed - 1 - eol_i);
		free(buffer);
		if (!(*(e->start)))
			return (-1);
		return (1);
	}
	if (!(*(e->line) = ft_strjoin_free3(*(e->line), buffer)))
		return (-1);
	return (1);
}

static int	get_next_line_main(t_gnl *e)
{
	long			eol_i;
	int				readed;
	char			*buffer;
	int				has_readed;

	has_readed = 0;
	if (!(buffer = malloc(sizeof(*buffer) * BUFF_SIZE + 1)))
		return (-1);
	while ((readed = read(e->fd, buffer, BUFF_SIZE)) != -1)
	{
		if (readed == 0 && !has_readed)
			return (0);
		has_readed = 1;
		buffer[readed] = '\0';
		if ((eol_i = get_eol(buffer)) != -1 || readed < BUFF_SIZE)
		{
			return (get_next_line_main_part(e, buffer, eol_i, readed));
		}
		if (!(*(e->line) = ft_strjoin_free1(*(e->line), buffer)))
			return (-1);
	}
	free(buffer);
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*start[256];
	t_gnl			e;
	long			eol_i;

	if (!line || fd < 0 || fd > 255 || !(*line = malloc(sizeof(**line))))
		return (-1);
	*line[0] = '\0';
	if (start[fd] && ft_strlen(start[fd]) > 0)
	{
		if ((eol_i = get_eol(start[fd])) != -1)
		{
			*line = ft_strsub(start[fd], 0, eol_i);
			start[fd] = ft_strsub(start[fd], eol_i + 1
					, ft_strlen(start[fd]) - 1 - eol_i);
			return (1);
		}
		*line = ft_strdup(start[fd]);
		free(start[fd]);
		start[fd] = NULL;
	}
	e.line = line;
	e.start = &(start[fd]);
	e.fd = fd;
	return (get_next_line_main(&e));
}
