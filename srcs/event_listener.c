/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:34:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 19:43:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int		key_listener(int key, void *data)
{
	if (key == 53)
		exit(0);
	(void)data;
	return (0);
}

int		loop_listener(void *data)
{
	t_env	*env;

	env = (t_env*)data;
	scenar_rain(env);
	flow(env);
	draw(env);
	return (0);
}
