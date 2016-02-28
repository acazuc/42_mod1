/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_rain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:20:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/28 11:42:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#define WTR(x, y) (env->water_tmp[x][y] + env->map[x][y])

void	flow_rain(t_env *env)
{
	int		add;
	int		flowest[4];
	int		lower;
	int		lowest;
	int		x;
	int		y;

	water_bck(env);
	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			flowest[0] = WTR(x, y);
			if (x > 0)
				flowest[0] = WTR(x - 1, y);
			flowest[1] = WTR(x, y);
			if (x < MAP_SIZE - 1)
				flowest[1] = WTR(x + 1, y);
			flowest[2] = WTR(x, y);
			if (y > 0)
				flowest[2] = WTR(x, y - 1);
			flowest[3] = WTR(x, y);
			if (y < MAP_SIZE - 1)
				flowest[3] = WTR(x, y + 1);
			if ((flowest[0] <= WTR(x, y))
					&& (flowest[1] <= WTR(x, y))
					&& (flowest[2] <= WTR(x, y))
					&& (flowest[3] <= WTR(x, y)))
				add = -1;
			else
				add = 0;
			lower = 0;
			lowest = WTR(x, y) + add;
			if (x > 0 && WTR(x - 1, y) < lowest && env->water_tmp[x][y] > 0 && env->water[x][y] > 0)
			{
				lower = 1;
				lowest = WTR(x - 1, y);
			}
			else if (x < MAP_SIZE - 1 && WTR(x + 1, y) < lowest && env->water_tmp[x][y] > 0 && env->water[x][y] > 0)
			{
				lower = 2;
				lowest = WTR(x + 1, y);
			}
			else if (y > 0 && WTR(x, y - 1) < lowest && env->water_tmp[x][y] > 0 && env->water[x][y] > 0)
			{
				lower = 3;
				lowest = WTR(x, y - 1);
			}
			else if (y < MAP_SIZE - 1 && WTR(x, y + 1) < lowest && env->water_tmp[x][y] > 0 && env->water[x][y] > 0)
			{
				lower = 4;
				lowest = WTR(x, y + 1);
			}
			if (lower == 1)
			{
				env->water[x - 1][y]++;
				env->water[x][y]--;
			}
			if (lower == 2)
			{
				env->water[x + 1][y]++;
				env->water[x][y]--;
			}
			if (lower == 3)
			{
				env->water[x][y - 1]++;
				env->water[x][y]--;
			}
			if (lower == 4)
			{
				env->water[x][y + 1]++;
				env->water[x][y]--;
			}
			y++;
		}
		x++;
	}
}
