/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_wave.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 18:39:54 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/28 11:06:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#define WTR(x, y) (env->water_tmp[x][y] + env->map[x][y])

void	flow_escaping(t_env *env)
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
			if (env->water_tmp[x][y] > 0 && (
						(x > 0 && WTR(x - 1, y) < WTR(x, y))
					|| (y > 0 && WTR(x, y - 1) < WTR(x, y))
					|| (y < MAP_SIZE - 1 && WTR(x, y + 1) < WTR(x, y))
					|| (x < MAP_SIZE - 1 && WTR(x + 1, y) < WTR(x, y))))
				env->water[x][y]--;
			y++;
		}
		x++;
	}
}
