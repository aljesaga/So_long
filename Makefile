# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 13:00:39 by alsanche          #+#    #+#              #
#    Updated: 2022/04/22 13:24:05 by alsanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c ./maping/prints.c ./maping/analysis.c \
	ipu.c ./keys_move/wasd.c ./gnl/get_next_line.c \
	./gnl/get_next_line_utils.c ./keys_move/hooks.c \
	./keys_move/wasd.c ft_free.c

OBJS = $(SRC:%.c=%.o)

CC = gcc

DFLAGS = -fsanitize=address

MLBFLAGS = -lmlx -framework OpenGL -framework AppKit

WFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./Libft
	$(CC) $^ -o $@ $(CFLAGS) ./Libft/libft.a $(MLBFLAGS)

clean:
	make clean -sC ./Libft
	rm -rf $(OBJS)

fclean:
	make fclean -sC ./Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean 
