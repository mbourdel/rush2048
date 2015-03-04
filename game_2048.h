/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:08:55 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/01 22:00:29 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft/libft.h"
# include <curses.h>
# include <time.h>

typedef enum e_const		t_win;
enum					e_const
{
	WIN_VALUE = 2048
};

/*
**like usual a big fat struct env :)
*/
typedef struct s_env	t_env;
struct					s_env
{
	int					**grille;
	int					xy[2];
	int					score;
};

void					icolor(void);
void					ft_small(void);
void					add_new_rand(t_env *env, int ch);
void					init_grille(t_env *env);
void					ft_board(int x, int y, t_env *env);
void					ft_resize(t_env *env);
void					move_up(t_env *env);
void					move_down(t_env *env);
void					move_left(t_env *env);
void					move_right(t_env *env);
int						end_game(t_env *env);
int						ft_gg_or_not_gg(int gg, int wn, t_env *env);
#endif
