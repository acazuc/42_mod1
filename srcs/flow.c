/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:23:55 by glavanan          #+#    #+#             */
/*   Updated: 2016/02/26 19:49:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#define TOPWATER(x,y) (env->water[x][y] + env->map[x][y])

static void		check(t_env *env, int x0, int y0, int x1, int y1)
{
	double	diff;

	if (TOPWATER(x1, y1) < TOPWATER(x0, y0) && env->water[x0][y0] > 0)
	{
		if (env->water[x0][y0] >= 1 && TOPWATER(x1, y1) + env->water[x0][y0] <= env->map[x0][y0])
		{
			env->water[x1][y1] += env->water[x0][y0];
			env->water[x0][y0] = 0;
			return ;
		}
		diff = (TOPWATER(x0, y0) - TOPWATER(x1, y1)) / FLOW_FACTOR;
		env->water[x1][y1] += diff;
		env->water[x0][y0] -= diff;
	}
}

void	flow(t_env *env)
{
	double	lower;
	int		lowest;
	int		x;
	int		y;

	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			if (env->water[x][y] > 0)
			{
				lowest = 0;
				lower = TOPWATER(x, y);
				if (y > 0 && TOPWATER(x, y - 1) < lower)
				{
					lower = TOPWATER(x, y - 1);
					lowest = 1;
				}
				if (y < MAP_SIZE - 1 && TOPWATER(x, y + 1) < lower)
				{
					lower = TOPWATER(x, y + 1);
					lowest = 2;
				}
				if (x > 0 && TOPWATER(x - 1, y) < lower)
				{
					lower = TOPWATER(x - 1, y);
					lowest = 3;
				}
				if (x < MAP_SIZE - 1 && TOPWATER(x + 1, y) < lower)
				{
					lower = TOPWATER(x + 1, y);
					lowest = 4;
				}
				if (lowest == 1)
					check(env, x, y, x, y - 1);
				if (lowest == 2)
					check(env, x, y, x, y + 1);
				if (lowest == 3)
					check(env, x, y, x - 1, y);
				if (lowest == 4)
					check(env, x, y, x + 1, y);
			}
			y++;
		}
		x++;
	}
}
