/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_uprising.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:28:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/27 11:45:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_uprising(t_env *env)
{
	int		x;
	int		y;

	if (env->scenar_count >= MAP_SIZE / 2)
		return ;
	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (env->map[y][x] < env->scenar_count)
				env->water[y][x] = env->scenar_count - env->map[y][x];
			x++;
		}
		y++;
	}
	env->scenar_count++;
}
