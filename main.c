/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:12:49 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/01 19:50:18 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	check_enum(void)
{
	int		a;
	t_win	e;

	e = WIN_VALUE;
	if ((int)e == 1073741825)
	{
		wclear(stdscr);
		waddstr(stdscr, "ENUM INCORECT ! : Please check the .h");
		refresh();
		getch();
		exit(0);
	}
	a = 2;
	while (a != (int)e && a < (int)e)
		a = a * 2;
	if (a != (int)e)
	{
		wclear(stdscr);
		waddstr(stdscr, "ENUM INCORECT ! : Please check the .h");
		refresh();
		getch();
		exit(0);
	}
	return ;
}

static void	ft_init(void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	start_color();
	icolor();
	return ;
}

int			main(void)
{
	int		ch;
	int		wn;
	t_env	env;

	env.xy[0] = 0;
	env.xy[1] = 0;
	ft_init();
	check_enum();
	init_grille(&env);
	wn = 0;
	while (1)
	{
		ft_resize(&env);
		if ((ch = getch()) == 27)
		{
			free(env.grille);
			exit(0);
		}
		if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_RIGHT || ch == KEY_LEFT)
			add_new_rand(&env, ch);
		wn = ft_gg_or_not_gg(end_game(&env), wn, &env);
		if (ch == KEY_END)
			main();
	}
	return (0);
}
