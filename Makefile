NAME_PUSH_SWAP= push_swap.exe

SRC_PUSH_SWAP = push_swap.c moves.c

HEADERFILES = push_swap.h 

CC = gcc

OBJ_P = $(SRC_PUSH_SWAP:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME_PUSH_SWAP)

$(NAME_PUSH_SWAP): $(OBJ_P)
	make -C Libft
	$(CC) -o $(NAME_PUSH_SWAP) -Llibft -lft $(OBJ_P)

%.o: %.c
	$(CC) -c $(FLAG) $< -o $@ $(HEADERFILES)

clean:
	make clean -C Libft
	rm -f $(OBJ_P)

fclean: clean
	make fclean -C Libft
	rm -f $(NAME_PUSH_SWAP)

.PHONY: clean fclean all