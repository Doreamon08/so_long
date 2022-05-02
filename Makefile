# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 20:16:04 by rabbie            #+#    #+#              #
#    Updated: 2022/05/02 14:42:54 by rabbie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = game_files/check_valid_map.c\
       game_files/close_game.c\
       game_files/error.c\
       game_files/main.c\
       game_files/map.c\
       game_files/move_player.c\
	   game_files/renders.c\
       game_files/utils.c\
	   get_next_line/get_next_line_utils.c\
	   get_next_line/get_next_line.c\

OBJ = $(SRCS:.c=.o)

CC = gcc

INC = -I ./game_files -I ./minilibx-linux -I ./get_next_line

LIB = -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME) $(OBJ)

$(NAME) : $(OBJ)
	make -C minilibx-linux
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

game_files/%.o: game_files/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
	rm -f $(OBJ)

fclean : clean
	$(RM) $(NAME)
	make clean -C minilibx-linux

re : fclean all