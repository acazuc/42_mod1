/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:22:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/26 10:46:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int		valid_int(char *arg)
{
	if (arg[0] == '-')
	{
		if (ft_strlen(arg) > 11)
			return (0);
	}
	else if (ft_strlen(arg) > 10)
		return (0);
	if (ft_atol(arg) > INT_MAX || ft_atol(arg) < INT_MIN)
		return (0);
	return (1);
}
