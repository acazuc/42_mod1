/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:24:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/27 20:39:14 by acazuc           ###   ########.fr       */
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
	int			**water;
	int			**water_tmp;
	int			scenar_count;
}				t_env;

#endif
