/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:23:55 by glavanan          #+#    #+#             */
/*   Updated: 2016/02/26 18:19:01 by glavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

# define TOPWATER(x,y) (env->water[x][y] + env->map[x][y])
# define TMPWATER (env->map[x][y] + env->water[x][y])

# define FACTOR 1.5

void		flow(t_env *env)
{
	int		x;
	int		y;
	double		dif;

	x = 0;
//	water_bck(env);
	while (x < MAP_SIZE)
	{
		y = 0;
		while(y < MAP_SIZE)
		{
			if (x > 0 && TOPWATER(x - 1, y) < TMPWATER && env->water[x][y] > 0)
			{
				dif = (TOPWATER(x,y) - TOPWATER(x -1, y))/FACTOR;
				env->water[x - 1][y] += dif;
				env->water[x][y] -= dif;
			}
			if (x < MAP_SIZE - 1 && TOPWATER(x + 1, y) < TMPWATER && env->water[x][y] > 0)
			{
				dif = (TOPWATER(x,y) - TOPWATER(x +1, y))/FACTOR;
				env->water[x + 1][y] += dif;
				env->water[x][y] -= dif;
			}
			if (y > 0 && TOPWATER(x, y - 1) < TMPWATER && env->water[x][y] > 0)
			{
				dif = (TOPWATER(x,y) - TOPWATER(x, y - 1))/FACTOR;
				env->water[x][y - 1] += dif;
				env->water[x][y] -= dif;
			}
			if (y < MAP_SIZE - 1 && TOPWATER(x, y + 1) < TMPWATER && env->water[x][y] > 0)
			{
				dif = (TOPWATER(x,y) - TOPWATER(x, y+1))/FACTOR;
				env->water[x][y + 1] +=dif;
				env->water[x][y] -= dif;
			}
			y++;
		}
		x++;
	}
}
