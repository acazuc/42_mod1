/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:24:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 16:33:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "window.h"

typedef struct	s_env
{
	t_window	*window;
	int			**map;
	double		**water;
	double		**water_tmp;
	int			uprising_count;
	int			mdr;
}				t_env;

#endif
