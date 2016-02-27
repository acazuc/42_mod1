/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_apocalypse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:54:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/27 12:58:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_apocalypse(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (x < env->scenar_count / 10 || y < env->scenar_count / 10
					|| x >= MAP_SIZE - env->scenar_count / 10
					|| y >= MAP_SIZE - env->scenar_count / 10)
				env->water[y][x] = MAP_SIZE / 4 - env->map[y][x];
			x++;
		}
		y++;
	}
	env->scenar_count++;
}
