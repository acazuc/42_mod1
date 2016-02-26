/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:26:14 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 11:17:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
	{
		ft_putendl("Usage: mod1 map");
		exit(0);
	}
	if (!(env.window = malloc(sizeof(*env.window))))
		error_quit("Failed to malloc window");
	map_init(&env);
	map_parse(&env, av[1]);
	map_post_load(&env);
	ft_putendl("initialized map");
	env.window->width = 1000;
	env.window->height = 750;
	window_init(&env);
	draw(&env);
	mlx_key_hook(env.window->mlx_window, key_listener, &env);
	mlx_loop(env.window->mlx);
	return (0);
}
