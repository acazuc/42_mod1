/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:39:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 19:17:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static void		draw_water(t_env *env, int x, int y)
{
	int		xd;
	int		yd;
	int		i;

	i = 0;
	if (y < MAP_SIZE - 1 && x > 0 && env->map[y + 1][x - 1]
			+ env->water[y + 1][x - 1] > env->map[y][x])
		i = env->map[y + 1][x - 1] + env->water[y + 1][x - 1]
			- env->map[y][x] - 1;
	while (i < env->water[y][x])
	{
		xd = get_screen_x(x, y, env->map[y][x] + i + 1);
		yd = get_screen_y(x, y, env->map[y][x] + i + 1);
		pixel_put(env, xd, yd, 255);
		i++;
	}
}

void			draw(t_env *env)
{
	int		dx;
	int		dy;
	int		y;
	int		x;

	window_reset(env);
	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			dx = get_screen_x(x, y, env->map[y][x]);
			dy = get_screen_y(x, y, env->map[y][x]);
			pixel_put(env, dx, dy, get_map_color(env->map[y][x]));
			pixel_put(env, dx, dy + 1, get_map_color(env->map[y][x]));
			draw_water(env, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->window->mlx, env->window->mlx_window
			, env->window->img, 0, 0);
}
