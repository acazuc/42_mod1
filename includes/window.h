/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:44:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 13:37:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct			s_window
{
	void				*mlx_window;
	void				*mlx;
	void				*img;
	char				*data;
	int					width;
	int					height;
	int					bpp;
	int					endian;
}						t_window;

#endif
