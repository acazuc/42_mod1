/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_place_mount_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:21:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 17:05:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static void		place_mount(t_env *env, char *mount)
{
	char	**splitted;
	char	*str;

	if (!(str = ft_strsub(mount, 1, ft_strlen(mount) - 2)))
		error_quit("Failed to sub mount");
	if (!(splitted = ft_strsplit(str, ',')))
		error_quit("Failed to split mount");
	if (!splitted[0] || !valid_int(splitted[0])
			|| !splitted[1] || !valid_int(splitted[1])
			|| !splitted[2] || !valid_int(splitted[2]))
		error_quit("Invalid mount position");
	map_place_mount(env, ft_atoi(splitted[0]), ft_atoi(splitted[1])
			, ft_atoi(splitted[2]));
}

void			map_place_mount_line(t_env *env, char *line)
{
	char	**mounts;
	int		i;

	if (!(mounts = ft_strsplit(line, ' ')))
		error_quit("Failed to split mounts");
	i = 0;
	while (mounts[i])
	{
		place_mount(env, mounts[i]);
		i++;
	}
}
