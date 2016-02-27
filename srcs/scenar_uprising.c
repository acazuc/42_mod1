/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenar_uprising.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:28:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/27 19:51:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static int	lowest = INT_MAX;

static void		calc_lowest(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < MAP_SIZE)
	{
		y = 0;
		while (y < MAP_SIZE)
		{
			if (x == 0 || y == 0 || x == MAP_SIZE - 1 || y == MAP_SIZE - 1)
				if (env->map[x][y] < lowest)
					lowest = env->map[x][y];
			y++;
		}
		x++;
	}
}

static void	recur_lowest(t_env *env, int x, int y)
{
	if (env->map[x][y] != lowest || env->water[x][y] + env->map[x][y] == env->scenar_count / 20)
		return ;
	env->water[x][y] = env->scenar_count / 20 - env->map[x][y];
	if (env->water[x][y] < 0)
		env->water[x][y] = 0;
	if (x > 0)
		recur_lowest(env, x - 1, y);
	if (x < MAP_SIZE - 1)
		recur_lowest(env, x + 1, y);
	if (y > 0)
		recur_lowest(env, x, y - 1);
	if (y < MAP_SIZE - 1)
		recur_lowest(env, x, y + 1);
}

void	scenar_uprising(t_env *env)
{
	int		x;
	int		y;

	if (lowest == INT_MAX)
		calc_lowest(env);
	if (env->scenar_count >= MAP_SIZE / 2 * 20)
		return ;
	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (x == 0 || y == 0 || x == MAP_SIZE - 1 || y == MAP_SIZE - 1)
				if (env->map[x][y] == lowest)
					recur_lowest(env, x, y);
			x++;
		}
		y++;
	}
	env->scenar_count++;
}
