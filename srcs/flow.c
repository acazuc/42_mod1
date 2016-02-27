/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:23:55 by glavanan          #+#    #+#             */
/*   Updated: 2016/02/27 18:51:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#define TOPWATER(x,y) (env->water_tmp[x][y] + env->map[x][y])
#define MIN 0.001
/*
static void		check(t_env *env, int x0, int y0, int x1, int y1, int count)
{
	double	diff;

	if (env->water[x0][y0] < MIN)
		diff = env->water[x0][y0];
	else
		diff = (double)(TOPWATER(x0, y0) - TOPWATER(x1, y1)) / 2;
	if (diff > env->water[x0][y0])
		diff = env->water[x0][y0];
	env->water[x1][y1] += diff;
	env->water[x0][y0] -= diff;
	(void)count;
}*/

void	flow(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	water_bck(env);
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			if (env->water_tmp[x][y] > 0)
			{
				env->water[x][y] += env->water_tmp[x][y];
				if (x > 0 && TOPWATER(x - 1, y) < TOPWATER(x, y))
				{
					env->water[x - 1][y]++;
					env->water[x][y]--;
				}
				if (x < MAP_SIZE - 1 && TOPWATER(x + 1, y) < TOPWATER(x, y))
				{
					env->water[x + 1][y]++;
					env->water[x][y]--;
				}
				if (env->water[x][y] < 0)
					env->water[x][y] = 0;
				/*lowest = 0;
				lower = TOPWATER(x, y);
				count = 0;
				if (y > 0 && TOPWATER(x, y - 1) < lower - MIN)
					count++;
				if (y < MAP_SIZE - 1 && TOPWATER(x, y + 1) < lower - MIN)
					count++;
				if (x > 0 && TOPWATER(x - 1, y) < lower - MIN)
					count++;
				if (x < MAP_SIZE - 1 && TOPWATER(x + 1, y) < lower - MIN)
					count++;
				env->water[x][y] += env->water_tmp[x][y];
				if (count > 0)
				{
					if (y > 0 && TOPWATER(x, y - 1) < TOPWATER(x, y) - MIN)
						check(env, x, y, x, y - 1, count);
					if (y < MAP_SIZE - 1 && TOPWATER(x, y + 1) < TOPWATER(x, y) - MIN)
						check(env, x, y, x, y + 1, count);
					if (x > 0 && TOPWATER(x - 1, y) < TOPWATER(x, y) - MIN)
						check(env, x, y, x - 1, y, count);
					if (x < MAP_SIZE - 1 && TOPWATER(x + 1, y) < TOPWATER(x, y) - MIN)
						check(env, x, y, x + 1, y, count);
				}*/
			}
			y++;
		}
		x++;
	}
}
