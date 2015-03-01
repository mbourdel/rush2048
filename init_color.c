/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:58:13 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/01 15:48:38 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		icolor(void)
{
	init_color(COLOR_BLACK, 115, 0, 50);
	init_color(COLOR_BLUE, 30, 0, 700);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_GREEN, COLOR_BLACK);
	init_pair(8, COLOR_YELLOW, COLOR_BLACK);
	init_pair(9, COLOR_BLUE, COLOR_BLACK);
	init_pair(10, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(11, COLOR_CYAN, COLOR_BLACK);
	init_pair(12, COLOR_RED, COLOR_BLUE);
	return ;
}
