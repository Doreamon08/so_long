# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 20:16:04 by rabbie            #+#    #+#              #
#    Updated: 2022/04/27 20:29:31 by rabbie           ###   ########.fr        #
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
	   ../get_next_line/get_next_line_utils.c\
	   ../get_next_line/get_next_line.c\
       ft_split.c\
        
HEADER = header.h get_next_line/get_next_line.h

OBJ = $(SRCS:.c=.o)

OBJ_B = $(SRCS_B:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lX11 -lXext -lmlx

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_BONUS)

clean :
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all