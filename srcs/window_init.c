/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:25:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 09:36:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	window_init(t_env *env)
{
	int		loul;

	env->window->bpp = 8 * 3;
	env->window->endian = 1;
	loul = env->window->width * env->window->bpp / 8;
	if (!(env->window->mlx = mlx_init()))
		error_quit("Failed to init mlx context");
	if (!(env->window->mlx_window = mlx_new_window(env->window->mlx
					, env->window->width
					, env->window->height, "acazuc's mod1")))
		error_quit("Failed to create window");
	if (!(env->window->img = mlx_new_image(env->window->mlx
					, env->window->width, env->window->height)))
		error_quit("Failed to create image");
	if (!(env->window->data = mlx_get_data_addr(env->window->img
					, &(env->window->bpp), &loul
					, &(env->window->endian))))
		error_quit("Failed to get image data");
}
