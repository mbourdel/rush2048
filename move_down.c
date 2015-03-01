/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:03:07 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/01 15:41:25 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		check_down(t_env *env, int i, int j, int *s)
{
	int		k;

	k = j;
	while (j + 1 < 3 && env->grille[i][j + 1] == 0)
		j += 1;
	if (env->grille[i][j + 1] == 0)
	{
		env->grille[i][j + 1] = env->grille[i][k];
		env->grille[i][k] = 0;
	}
	else if (env->grille[i][j + 1] == env->grille[i][k] && *s != j + 1)
	{
		env->grille[i][j + 1] *= 2;
		*s = j + 1;
		env->grille[i][k] = 0;
	}
	else if (j != k || *s == j + 1)
	{
		env->grille[i][j] = env->grille[i][k];
		env->grille[i][k] = 0;
	}
}

void			move_down(t_env *env)
{
	int		i;
	int		j;
	int		s;

	i = 3;
	while (i >= 0)
	{
		j = 3;
		s = 4;
		while (j >= 0)
		{
			if (env->grille[i][j] != 0 && j != 3)
				check_down(env, i, j, &s);
			j--;
		}
		i--;
	}
}
