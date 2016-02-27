/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_geyser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:54:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/27 19:57:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#define WTR(x, y) (env->water_tmp[x][y] + env->map[x][y])

void	flow_geyser(t_env *env)
{
	int		x;
	int		y;

	water_bck(env);
	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			if ((x > 0 && env->water_tmp[x - 1][y] > 0 && WTR(x - 1, y) > WTR(x, y))
					|| (y > 0 && env->water_tmp[x][y - 1] > 0 && WTR(x, y - 1) > WTR(x, y))
					|| (y < MAP_SIZE - 1 && env->water_tmp[x][y + 1] > 0 && WTR(x, y + 1) > WTR(x, y))
					|| (x < MAP_SIZE - 1 && env->water_tmp[x + 1][y] > 0 && WTR(x + 1, y) > WTR(x, y)))
				env->water[x][y]++;
			y++;
		}
		x++;
	}
}
