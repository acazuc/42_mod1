/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_rain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:41:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 19:28:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_rain(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (rand() < RAND_MAX * RAIN_RAND)
				env->water[y][x]++;
			x++;
		}
		y++;
	}
}
