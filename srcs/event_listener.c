/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:34:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 14:17:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int		key_listener(int key, void *data)
{
	t_env	*env;

	env = (t_env *)data;
	if (key == 53)
		exit(0);
	if (key == 69)
		if (env->mdr < MAP_SIZE / 2)
			env->mdr++;
	if (key == 78)
		if (env->mdr > 0)
			env->mdr--;
	int x = 0;
	while (x < MAP_SIZE)
	{
		int y = 0;
		while (y < MAP_SIZE)
		{
			if (env->map[y][x] < env->mdr)
				env->water[y][x] = env->mdr - env->map[y][x];
			else
				env->water[y][x] = 0;
			y++;
		}
		x++;
	}
	draw(env);
	return (0);
}
