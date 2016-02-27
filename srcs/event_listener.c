/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:34:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/27 20:25:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int		key_listener(int key, void *data)
{
	t_env	*env;

	env = (t_env*)data;
	if (key == 53)
		exit(0);
	if (key == 14 && env->scenario != EMPTYING)
		env->scenario = ESCAPING;
	else if (key == 9 && env->scenario != ESCAPING)
		env->scenario = EMPTYING;
	return (0);
}

int		loop_listener(void *data)
{
	t_env	*env;

	env = (t_env*)data;
	if (env->scenario == RAIN)
	{
		scenar_rain(env);
		flow_rain(env);
	}
	else if (env->scenario == UPRISING)
	{
		scenar_uprising(env);
		flow_uprising(env);
	}
	else if (env->scenario == WAVE)
	{
		scenar_wave(env);
		flow_wave(env);
	}
	else if (env->scenario == GEYSER)
	{
		scenar_geyser(env);
		flow_wave(env);
	}
	else if (env->scenario == APOCALYPSE)
	{
		flow_uprising(env);
		scenar_apocalypse(env);
	}
	else if (env->scenario == EMPTYING)
		scenar_emptying(env);
	else if (env->scenario == ESCAPING)
	{
		flow_rain(env);
		scenar_escaping(env);
	}
	draw(env);
	return (0);
}
