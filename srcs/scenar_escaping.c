/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_escaping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:10:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/27 16:59:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static double	lowest_value(t_env *env)
{
	double	lowest;
	int		x;
	int		y;

	lowest = MAP_SIZE / 2;
	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (env->map[y][x] < lowest)
				lowest = env->map[y][x];
			x++;
		}
		y++;
	}
	return (lowest);
}

void	scenar_escaping(t_env *env)
{
	double	lowest;
	int		x;
	int		y;

	lowest = lowest_value(env);
	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (env->map[y][x] <= lowest + 10 || x == 0 || y == 0 || x == MAP_SIZE - 1 || y == MAP_SIZE - 1)
				env->water[y][x] -= 0.1;
			x++;
		}
		y++;
	}
}
