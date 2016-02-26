/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:16:19 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 09:39:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	pixel_put(t_env *env, int x, int y, int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	c;

	c = mlx_get_color_value(env->window->mlx, color);
	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	if (x >= 0 && x < env->window->width
			&& y >= 0 && y < env->window->height)
	{
		env->window->data[y * env->window->width * env->window->bpp / 8
			+ env->window->bpp / 8 * x] = b;
		env->window->data[y * env->window->width * env->window->bpp / 8
			+ env->window->bpp / 8 * x + 1] = g;
		env->window->data[y * env->window->width * env->window->bpp / 8
			+ env->window->bpp / 8 * x + 2] = r;
	}
}
