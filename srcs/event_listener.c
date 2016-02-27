/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:34:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/27 20:02:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int		key_listener(int key, void *data)
{
	t_env	*env;

	env = (t_env*)data;
	if (key == 53)
		exit(0);
	/*if (key == 18)
	{
		env->scenar_count = 0;
		env->scenario = RAIN;
	}
	else if (key == 19)
	{
		env->scenar_count = 0;
		env->scenario = UPRISING;
	}
	else if (key == 20)
	{
		env->scenar_count = 0;
		env->scenario = WAVE;
	}
	else if (key == 21)
		env->scenario = GEYSER;
	else if (key == 22)
	{
		env->scenar_count = 0;
		env->scenario = APOCALYPSE;
	}
	else if (key == 14)
		env->scenario = ESCAPING;
	else if (key == 9)
		env->scenario = EMPTYING;
	else if (key == 15)
		water_reset(env);*/
	scenar_wave(env);
	flow_wave(env);
	draw(env);
	return (0);
}

int		loop_listener(void *data)
{
	t_env	*env;

	env = (t_env*)data;
	/*if (env->scenario == RAIN)
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
		scenar_apocalypse(env);
	else if (env->scenario == EMPTYING)
		scenar_emptying(env);
	else if (env->scenario == ESCAPING)
		scenar_escaping(env);
	for (int i = 0; i < 1; i++)
		flow(env);
	draw(env);*/
	scenar_wave(env);
	flow_wave(env);
	draw(env);
	return (0);
}
