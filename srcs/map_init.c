/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:40:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 14:05:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static void		water_init_bck(t_env *env)
{
	int		x;
	int		y;

	if (!(env->water_tmp = malloc(sizeof(*env->water_tmp) * MAP_SIZE)))
		error_quit("Failed to malloc map");
	y = 0;
	while (y < MAP_SIZE)
	{
		if (!(env->water_tmp[y] = malloc(sizeof(**env->water_tmp) * MAP_SIZE)))
			error_quit("Failed to malloc map");
		x = 0;
		while (x < MAP_SIZE)
		{
			env->water_tmp[y][x] = 0;
			x++;
		}
		y++;
	}

}

static void		water_init(t_env *env)
{
	int		x;
	int		y;

	if (!(env->water = malloc(sizeof(*env->water) * MAP_SIZE)))
		error_quit("Failed to malloc map");
	y = 0;
	while (y < MAP_SIZE)
	{
		if (!(env->water[y] = malloc(sizeof(**env->water) * MAP_SIZE)))
			error_quit("Failed to malloc map");
		x = 0;
		while (x < MAP_SIZE)
		{
			env->water[y][x] = 0;
			x++;
		}
		y++;
	}

}

void	map_init(t_env *env)
{
	int		x;
	int		y;

	if (!(env->map = malloc(sizeof(*env->map) * MAP_SIZE)))
		error_quit("Failed to malloc map");
	y = 0;
	while (y < MAP_SIZE)
	{
		if (!(env->map[y] = malloc(sizeof(**env->map) * MAP_SIZE)))
			error_quit("Failed to malloc map");
		x = 0;
		while (x < MAP_SIZE)
		{
			env->map[y][x] = 0;
			x++;
		}
		y++;
	}
	water_init_bck(env);
	water_init(env);
}
