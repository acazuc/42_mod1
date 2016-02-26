/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scree_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:51:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 11:01:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int		get_screen_x(int x, int y, int z)
{
	return ((int)(x / (double)MAP_SIZE * 500. + y / (double)MAP_SIZE * 500.));
	(void)z;
}

int		get_screen_y(int x, int y, int z)
{
	return (750 + (int)(x / (double)MAP_SIZE * -250. + y / (double)MAP_SIZE * 250. - z / (double)MAP_SIZE * 500.));
}
