NAME = push_swap
SRC = push_swap.c \
parse.c \
moves_a.c moves_b.c moves_a_b.c \
diff.c sorting.c \
calculating.c algomoves.c operations.c
LIBFT = ./Libft/libft.a
HEADERFILES = push_swap.h -ILibft/libft.h
OBJFILES = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc

$(NAME): $(OBJFILES)
	make -C Libft
	$(CC) $(CFLAGS) $(OBJFILES) ${LIBFT} -o $(NAME)

all: $(NAME)

%.o: ft_%.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<
	
bonus: $(OBJFILES)
	ar -rc $(NAME) $^

clean:
	make clean -C Libft
	rm -f $(OBJFILES)

fclean:
	make fclean -C Libft
	rm -f $(NAME) $(OBJFILES) ${LIBFT}

re: fclean all
	
.PHONY: clean fclean all re bonus