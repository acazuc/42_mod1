/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_geyser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:00:09 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/27 12:53:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_geyser(t_env *env)
{
	double	hyp;
	int		lvl;
	int		x;
	int		y;

	x = MAP_SIZE / 2 - MAP_SIZE / 20;
	while (x < MAP_SIZE / 2 + MAP_SIZE / 20)
	{
		y = MAP_SIZE / 2 - MAP_SIZE / 20;
		while (y < MAP_SIZE / 2 + MAP_SIZE / 20)
		{
			hyp = sqrt(pow(x - MAP_SIZE / 2, 2) + pow(y - MAP_SIZE / 2, 2));
			lvl = cos(hyp / (MAP_SIZE / 2)) * MAP_SIZE / 2;
			if (lvl < 0)
				lvl = 0;
			if (env->water[y][x] + env->map[y][x] < lvl)
				env->water[y][x] = lvl - env->map[y][x];
			y++;
		}
		x++;
	}
}
