/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_rain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:41:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 17:04:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	scenar_rain(t_env *env)
{
	int	x;
	int	y;
	int b;
	int c;

	srand(time(NULL));
	b = rand();
	c = 0;
	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (b & (1 << c))
				env->water[y][x]++;
			if (++c >= 63)
			{
				c = 0;
				b = rand();
			}
			x++;
		}
		y++;
	}
}
