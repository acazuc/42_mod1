/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:24:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/02 13:01:30 by acazuc           ###   ########.fr       */
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
	double			**map;
	double		**water;
	double		**water_tmp;
	int			scenar_count;
	int			flow_pause;
	int			pause;
}				t_env;

#endif
