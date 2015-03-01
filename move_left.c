/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:04:06 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/01 15:41:19 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		check_left(t_env *env, int i, int j, int *s)
{
	int		k;

	k = i;
	while (i - 1 > 0 && env->grille[i - 1][j] == 0)
		i -= 1;
	if (env->grille[i - 1][j] == 0)
	{
		env->grille[i - 1][j] = env->grille[k][j];
		env->grille[k][j] = 0;
	}
	else if (env->grille[i - 1][j] == env->grille[k][j] && *s != i - 1)
	{
		env->grille[i - 1][j] *= 2;
		env->grille[k][j] = 0;
		*s = i - 1;
	}
	else if (i != k || *s == i - 1)
	{
		env->grille[i][j] = env->grille[k][j];
		env->grille[k][j] = 0;
	}
}

void			move_left(t_env *env)
{
	int		i;
	int		j;
	int		s;

	j = 0;
	while (j < 4)
	{
		i = 0;
		s = 4;
		while (i < 4)
		{
			if (env->grille[i][j] != 0 && i != 0)
				check_left(env, i, j, &s);
			i++;
		}
		j++;
	}
}
