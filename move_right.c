/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:05:18 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/01 18:43:49 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		check_right(t_env *env, int i, int j, int *s)
{
	int		k;

	k = i;
	while (i + 1 < 3 && env->grille[i + 1][j] == 0)
		i += 1;
	if (env->grille[i + 1][j] == 0)
	{
		env->grille[i + 1][j] = env->grille[k][j];
		env->grille[k][j] = 0;
	}
	else if (env->grille[i + 1][j] == env->grille[k][j] && *s != i + 1)
	{
		env->grille[i + 1][j] *= 2;
		env->grille[k][j] = 0;
		*s = i + 1;
	}
	else if (i != k || *s == i + 1)
	{
		env->grille[i][j] = env->grille[k][j];
		env->grille[k][j] = 0;
	}
}

void			move_right(t_env *env)
{
	int		i;
	int		j;
	int		s;

	j = 3;
	while (j >= 0)
	{
		i = 3;
		s = 4;
		while (i >= 0)
		{
			if (env->grille[i][j] != 0 && i != 3)
				check_right(env, i, j, &s);
			i--;
		}
		j--;
	}
}
