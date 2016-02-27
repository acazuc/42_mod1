/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   water_bck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:00:36 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/27 11:24:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	water_bck(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			env->water_tmp[y][x] = env->water[y][x];
			env->water[y][x] = 0;
			y++;
		}
		x++;
	}
}
