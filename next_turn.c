/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:24:02 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/01 18:47:48 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		check_rand(int **tmp, t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tmp[i][j] != env->grille[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int		**cpy_grille(t_env *env)
{
	int		i;
	int		j;
	int		**tmp;

	tmp = (int**)malloc(sizeof(int*) * 4);
	i = 0;
	while (i < 4)
		tmp[i++] = (int*)malloc(sizeof(int) * 4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp[i][j] = env->grille[i][j];
			j++;
		}
		i++;
	}
	return (tmp);
}

static void		go_move(t_env *env, int ch)
{
	if (ch == KEY_LEFT)
		move_left(env);
	if (ch == KEY_RIGHT)
		move_right(env);
	if (ch == KEY_UP)
		move_up(env);
	if (ch == KEY_DOWN)
		move_down(env);
}

void			add_new_rand(t_env *env, int ch)
{
	int		i;
	int		j;
	int		**tmp;

	tmp = cpy_grille(env);
	go_move(env, ch);
	if (check_rand(tmp, env) == 1)
	{
		i = (int)(4.0 * rand() / (RAND_MAX + 1.0));
		j = (int)(4.0 * rand() / (RAND_MAX + 1.0));
		while (env->grille[i][j] != 0)
		{
			i = (int)(4.0 * rand() / (RAND_MAX + 1.0));
			j = (int)(4.0 * rand() / (RAND_MAX + 1.0));
		}
		if ((int)(10.0 * rand() / (RAND_MAX + 1.0)) != 0)
			env->grille[i][j] = 2;
		else
			env->grille[i][j] = 4;
		ft_board(env->xy[0], env->xy[1], env);
	}
}
