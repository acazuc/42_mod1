/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:34:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 18:22:08 by glavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int		key_listener(int key, void *data)
{
	t_env	*env;

	env = (t_env *)data;
	if (key == 53)
		exit(0);
	for (int i = 0 ; i < 100; i++)
	flow(env);
	draw(env);
	return (0);
}
