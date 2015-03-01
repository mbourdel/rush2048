/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:34:31 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/01 11:25:48 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		ft_resize(t_env *env)
{
	int		x;
	int		y;

	getmaxyx(stdscr, x, y);
	if (x != env->xy[0] || y != env->xy[1])
	{
		env->xy[0] = x;
		env->xy[1] = y;
		if (x < 12 || y < 10)
			ft_small();
		else
			ft_board(x, y, env);
		refresh();
	}
	return ;
}
