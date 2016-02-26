/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:32:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 09:29:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	error_quit(char *error_message)
{
	ft_putstr_fd("An error happened: ", 2);
	ft_putendl_fd(error_message, 2);
	exit(-1);
}
