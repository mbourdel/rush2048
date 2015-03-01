/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:34:33 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/01 12:13:39 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		ft_small(void)
{
	wclear(stdscr);
	addstr("Window to small\nPlease resize it");
	return ;
}
