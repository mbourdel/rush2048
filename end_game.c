/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:23:11 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/01 18:42:31 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		win_game(t_env *env)
{
	int		i;
	int		j;
	t_win	e;

	e = WIN_VALUE;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (env->grille[i][j] == (int)e)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int		loose_game(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (env->grille[i][j] == 0)
				return (0);
			if (j < 3 && env->grille[i][j] == env->grille[i][j + 1])
				return (0);
			if (i < 3 && env->grille[i][j] == env->grille[i + 1][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				end_game(t_env *env)
{
	if (loose_game(env) == 1)
		return (1);
	if (win_game(env) == 1)
		return (2);
	return (0);
}
