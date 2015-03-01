/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:01:16 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/01 15:41:29 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		check_up(t_env *env, int i, int j, int *s)
{
	int		k;

	k = j;
	while (j - 1 > 0 && env->grille[i][j - 1] == 0)
		j--;
	if (env->grille[i][j - 1] == 0)
	{
		env->grille[i][j - 1] = env->grille[i][k];
		env->grille[i][k] = 0;
	}
	else if (env->grille[i][j - 1] == env->grille[i][k] && *s != j - 1)
	{
		env->grille[i][j - 1] *= 2;
		env->grille[i][k] = 0;
		*s = j - 1;
	}
	else if (j != k || *s == j - 1)
	{
		env->grille[i][j] = env->grille[i][k];
		env->grille[i][k] = 0;
	}
}

void			move_up(t_env *env)
{
	int		i;
	int		j;
	int		s;

	i = 0;
	while (i < 4)
	{
		j = 0;
		s = 4;
		while (j < 4)
		{
			if (env->grille[i][j] != 0 && j != 0)
				check_up(env, i, j, &s);
			j++;
		}
		i++;
	}
}
