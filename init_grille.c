/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grille.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:39:22 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/01 21:51:45 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	init_grille(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	srand(time(NULL));
	(*env).grille = (int**)malloc(sizeof(int*) * 4);
	while (i < 4)
		(*env).grille[i++] = ft_memalloc(sizeof(int) * 4);
	i = (int)(4.0 * rand() / (RAND_MAX + 1.0));
	j = (int)(4.0 * rand() / (RAND_MAX + 1.0));
	if ((int)(10.0 * rand() / (RAND_MAX + 1.0)) != 0)
		(*env).grille[i][j] = 2;
	else
		(*env).grille[i][j] = 4;
	env->score += env->grille[i][j];
	while ((*env).grille[i][j] != 0)
	{
		i = (int)(4.0 * rand() / (RAND_MAX + 1.0));
		j = (int)(4.0 * rand() / (RAND_MAX + 1.0));
	}
	if ((int)(10.0 * rand() / (RAND_MAX + 1.0)) != 0)
		(*env).grille[i][j] = 2;
	else
		(*env).grille[i][j] = 4;
	env->score += env->grille[i][j];
}
