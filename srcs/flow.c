/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:23:55 by glavanan          #+#    #+#             */
/*   Updated: 2016/02/27 16:20:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#define TOPWATER(x,y) (env->water_tmp[x][y] + env->map[x][y])
#define MIN 0.01

static void		check(t_env *env, int x0, int y0, int x1, int y1, int count)
{
	double	diff;

	if (env->water[x0][y0] < MIN)
		diff = env->water[x0][y0];
	else
		diff = (double)(TOPWATER(x0, y0) - TOPWATER(x1, y1)) / (double)FLOW_FACTOR / (double)count;
	if (diff > env->water[x0][y0])
		diff = env->water[x0][y0];
	env->water[x1][y1] += diff;
	env->water[x0][y0] -= diff;
}
/*
static void		dump(t_env *env, int x0, int y0, int x1, int y1)
{
	env->water[x1][y1] += env->water_tmp[x0][y0];
	env->water[x0][y0] -= env->water_tmp[x0][y0];
}
*/

void	flow(t_env *env)
{
	double	lower;
	int		lowest;
	int		count;
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
				lowest = 0;
				lower = TOPWATER(x, y);/*
				if (y > 0 && TOPWATER(x, y - 1) < lower && TOPWATER(x, y - 1) + env->water_tmp[x][y] <= env->map[x][y])
				{
					lower = TOPWATER(x, y - 1);
					lowest = 1;
				}
				if (y < MAP_SIZE - 1 && TOPWATER(x, y + 1) < lower && TOPWATER(x, y + 1) + env->water_tmp[x][y] <= env->map[x][y])
				{
					lower = TOPWATER(x, y + 1);
					lowest = 2;
				}
				if (x > 0 && TOPWATER(x - 1, y) < lower && TOPWATER(x - 1, y) + env->water_tmp[x][y] <= env->map[x][y])
				{
					lower = TOPWATER(x - 1, y);
					lowest = 3;
				}
				if (x < MAP_SIZE - 1 && TOPWATER(x + 1, y) < lower && TOPWATER(x + 1, y) + env->water_tmp[x][y] <= env->map[x][y])
				{
					lower = TOPWATER(x + 1, y);
					lowest = 4;
				}
				if (lowest == 1)
					dump(env, x, y, x, y - 1);
				else if (lowest == 2)
					dump(env, x, y, x, y + 1);
				else if (lowest == 3)
					dump(env, x, y, x - 1, y);
				else if (lowest == 4)
					dump(env, x, y, x + 1, y);
				else*/
				{
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
					}
				}
			}
			y++;
		}
		x++;
	}
}
