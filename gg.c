/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:48:53 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/01 19:51:55 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	ft_looser(t_env *env)
{
	wclear(stdscr);
	waddstr(stdscr, "Epic fail: YOU LOOSE\nPress key to exit");
	refresh();
	getch();
	free(env->grille);
	exit(0);
	return ;
}

static void	ft_winner(t_env *env)
{
	wclear(stdscr);
	waddstr(stdscr, "YOU WIN\nPress key for make a fatality");
	refresh();
	if (getch() == 27)
	{
		free(env->grille);
		exit(0);
	}
	ft_board(env->xy[0], env->xy[1], env);
	return ;
}

int			ft_gg_or_not_gg(int gg, int wn, t_env *env)
{
	if (gg == 0 && !wn)
		return (0);
	if (gg == 1)
		ft_looser(env);
	if (gg == 2 && !wn)
		ft_winner(env);
	return (1);
}
