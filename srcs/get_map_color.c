/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:44:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 13:18:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static void		get_low_color(int height, int *r, int *g, int *b)
{
	*r = 128. * height / (MAP_SIZE / 4.);
	*g = 256. - 192. * height / (MAP_SIZE / 4.);
	*b = 25. * height / (MAP_SIZE / 4.);
}

static void		get_high_color(int height, int *r, int *g, int *b)
{
	height -= MAP_SIZE / 4.;
	*r = 128. + 128. * height / (MAP_SIZE / 4.);
	*g = 64. + 192. * height / (MAP_SIZE / 4.);
	*b = 25. + 231. * height / (MAP_SIZE / 4.);
}

int		get_map_color(int height)
{
	int		r;
	int		g;
	int		b;

	if (height == 0)
		return (0x00FF00);
	if (height < MAP_SIZE / 4)
		get_low_color(height, &r, &g, &b);
	else
		get_high_color(height, &r, &g, &b);
	return ((r << 16) + (g << 8) + b);
}
