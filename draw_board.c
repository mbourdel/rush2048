/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:22:15 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/01 18:29:24 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		ft_print_with_color(int i, char *tmp, int x, int y)
{
	short	clr;
	int		prout;
	int		l;

	prout = i;
	clr = 0;
	l = ft_strlen(tmp);
	while ((prout = (prout / 2)))
		clr++;
	if (clr > 11)
		clr = 11;
	wattron(stdscr, COLOR_PAIR(clr));
	mvaddstr(x, (y - (l / 2)), tmp);
	wattroff(stdscr, COLOR_PAIR(clr));
	return ;
}

static void		ft_nbr_to_board(int x, int y, t_env *env)
{
	int		i;
	int		j;
	int		startxy[2];
	char	*tmp;

	i = 0;
	startxy[1] = (y / 8);
	while (i < 4)
	{
		startxy[0] = (x / 8);
		j = 0;
		while (j < 4)
		{
			tmp = ft_itoa(env->grille[i][j++]);
			if (tmp[0] != '0')
				ft_print_with_color(env->grille[i][j - 1],
					tmp, startxy[0], startxy[1]);
			free(tmp);
			startxy[0] += (x / 4);
		}
		startxy[1] += (y / 4);
		i++;
	}
}

static void		ft_cross(int x, int y)
{
	mvhline((x / 4), (y / 4), '+', 1);
	mvhline((x / 4), (y / 2), '+', 1);
	mvhline((x / 4), ((y / 4) + (y / 2)), '+', 1);
	mvhline((x / 4), (y - 1), '+', 1);
	mvhline((x / 2), (y / 4), '+', 1);
	mvhline((x / 2), (y / 2), '+', 1);
	mvhline((x / 2), ((y / 4) + (y / 2)), '+', 1);
	mvhline((x / 2), (y - 1), '+', 1);
	mvhline(((x / 4) + (x / 2)), (y / 4), '+', 1);
	mvhline(((x / 4) + (x / 2)), (y / 2), '+', 1);
	mvhline(((x / 4) + (x / 2)), ((y / 4) + (y / 2)), '+', 1);
	mvhline(((x / 4) + (x / 2)), (y - 1), '+', 1);
	mvhline((x - 1), (y / 4), '+', 1);
	mvhline((x - 1), (y / 2), '+', 1);
	mvhline((x - 1), ((y / 4) + (y / 2)), '+', 1);
	mvhline((x - 1), (y / 4), '+', 1);
	mvhline((x - 1), (y / 2), '+', 1);
	mvhline((x - 1), ((y / 4) + (y / 2)), '+', 1);
	wattroff(stdscr, COLOR_PAIR(12));
	return ;
}

void			ft_board(int x, int y, t_env *env)
{
	wclear(stdscr);
	wattron(stdscr, COLOR_PAIR(12));
	border('|', '|', '-', '-', '+', '+', '+', '+');
	mvhline((x / 4), 1, '-', (y - 2));
	mvhline((x / 4), 0, '+', 1);
	mvhline((x / 2), 1, '-', (y - 2));
	mvhline((x / 2), 0, '+', 1);
	mvhline(((x / 4) + (x / 2)), 1, '-', (y - 2));
	mvhline(((x / 4) + (x / 2)), 0, '+', 1);
	mvvline(1, (y / 4), '|', (x - 2));
	mvvline(0, (y / 4), '+', 1);
	mvvline(1, (y / 2), '|', (x - 2));
	mvvline(0, (y / 2), '+', 1);
	mvvline(1, ((y / 4) + (y / 2)), '|', (x - 2));
	mvvline(0, ((y / 4) + (y / 2)), '+', 1);
	ft_cross(x, y);
	ft_nbr_to_board(x, y, env);
	return ;
}
