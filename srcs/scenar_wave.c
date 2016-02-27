/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_wave.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:23:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/27 11:49:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_wave(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->scenar_count / 10)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			env->water[y][x] = MAP_SIZE / 4 - env->map[y][x];
			x++;
		}
		y++;
	}
	env->scenar_count++;
}
