/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_uprising.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:28:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/28 10:44:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_uprising(t_env *env)
{
	int		x;
	int		y;

	if (env->scenar_count >= MAP_SIZE / 4 * 50)
		return ;
	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (x == 0 || y == 0 || x == MAP_SIZE - 1 || y == MAP_SIZE - 1)
			{
				env->water[x][y] = env->scenar_count / 50 - env->map[x][y];
				if (env->water[x][y] < 0)
					env->water[x][y] = 0;
			}
			x++;
		}
		y++;
	}
	env->scenar_count++;
}
