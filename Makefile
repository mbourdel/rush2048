# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 20:13:56 by mbourdel          #+#    #+#              #
#    Updated: 2015/03/01 17:01:43 by mbourdel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

SRC = main.c ft_resize.c init_grille.c next_turn.c ft_error.c
SRC	+= move_up.c move_down.c move_left.c move_right.c
SRC += draw_board.c init_color.c gg.c end_game.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft/

FLAG = -Wall -Werror -Wextra

NCURSE = -lcurses

all: $(NAME)

$(NAME):
	@cd $(LIBFT_PATH); $(MAKE) -f Makefile
	@gcc $(FLAG) -c $(SRC) $(NCURE)
	@gcc $(FLAG) $(OBJ) -o $(NAME) $(LIBFT_PATH)libft.a $(NCURSE)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|    game_2048    |"
	@echo "|   was summoned  |"
	@echo "[=================]"

clean:
	@rm -rf $(OBJ)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     XXXXX.o     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

fclean: clean
	@rm -rf $(NAME)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|    game_2048    |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

re: fclean all
