/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:39:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 11:09:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	draw(t_env *env)
{
	int		z;
	int		y;
	int		x;

	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			z = get_screen_y(x, y, env->map[y][x]);
			pixel_put(env, get_screen_x(x, y, env->map[y][x]), z, get_map_color(env->map[y][x]));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->window->mlx, env->window->mlx_window, env->window->img, 0, 0);
}
