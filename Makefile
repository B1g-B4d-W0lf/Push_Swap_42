NAME = push_swap.exe
SRC =	push_swap.c parse.c moves_a.c moves_b.c tempo_tools.c
LIBFT = libft.a
HEADERFILES = push_swap.h -ILibft/libft.h
OBJFILES = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc

$(NAME): $(OBJFILES)
	make -C Libft
	mv Libft/libft.a .
	$(CC) $(CFLAGS) $(OBJFILES) ${LIBFT} -o $(NAME)

all: $(NAME)

%.o: ft_%.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<
	
bonus: $(OBJFILES)
	ar -rc $(NAME) $^

clean:
	make clean -C Libft
	rm -f $(OBJFILES)
	rm -f ${LIBFT}

fclean:
	make fclean -C Libft
	rm -f $(NAME) $(OBJFILES) ${LIBFT}

re: fclean all
	
.PHONY: clean fclean all re bonus