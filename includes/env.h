/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:24:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 19:09:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "scenario.h"
# include "window.h"

typedef struct	s_env
{
	t_scenario	scenario;
	t_window	*window;
	int			**map;
	double		**water;
	int			uprising_count;
}				t_env;

#endif
