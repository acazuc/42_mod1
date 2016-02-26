/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:40:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 18:30:30 by glavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

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

void			map_init(t_env *env)
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
	water_init(env);
}
