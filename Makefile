NAME = so_long

SRC = so_long.c so_long.h ./maping/prints.c ./maping/analisys.c

OBJS = $(SRC:%.c=%.o)

CC = gcc

DFLAGS = -fsantize=address -g3

WFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -sC ../Libft
	$(CC) $^ -o $@ $(CFLAGS) $(DFLAGS) ../Libft/libft.a

clean:
	make fclean -sC ../Libft
	rm -rf $(OBJS)

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean 
