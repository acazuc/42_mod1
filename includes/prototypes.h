/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:28:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 14:14:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

void	window_init(t_env *env);
void	error_quit(char *msg);
int		key_listener(int key, void *data);
void	pixel_put(t_env *env, int x, int y, int color);
void	map_init(t_env *env);
int		get_map_color(int height);
void	draw(t_env *env);
int		get_screen_x(int x, int y, int z);
int		get_screen_y(int x, int y, int z);
void	map_post_load(t_env *env);
void	map_parse(t_env *env, char *file);
void	map_place_mount_line(t_env *env, char *line);
void	map_place_mount(t_env *env, int x, int y, int z);
int		valid_int(char *val);
void	window_reset(t_env *env);

#endif
