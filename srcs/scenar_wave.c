/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_wave.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:23:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/28 13:26:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_wave(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < 1)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			env->water[y][x] = env->scenar_count / 50;
			x++;
		}
		y++;
	}
	if (env->scenar_count < 2000)
		env->scenar_count++;
}
