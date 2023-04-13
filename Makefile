NAME = push_swap
NAME_B = checker
SRC = push_swap.c \
parse.c \
moves_a.c moves_b.c moves_a_b.c \
diff.c sorting.c \
calculating.c algomoves.c operations.c
SRC_BONUS = ./Checker/parse_bonus.c \
./Checker/moves_a_bonus.c ./Checker/moves_b_bonus.c ./Checker/moves_a_b_bonus.c \
./Checker/checker.c 
LIBFT = ./Libft/libft.a
HEADERFILES = -I push_swap.h Libft/libft.h Checker/push_swap_bonus.h
OBJFILES = $(SRC:.c=.o)
OBJBONUS = $(SRC_BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc

$(NAME): $(OBJFILES)
	make -C Libft
	$(CC) $(CFLAGS) $(OBJFILES) ${LIBFT} -o $(NAME)

$(NAME_B): $(OBJBONUS)
	make -C Libft
	$(CC) $(CFLAGS) $(OBJBONUS) ${LIBFT} -o $(NAME_B)

all: $(NAME)

#%.o: %.c $(HEADERFILES)
#	$(CC) -c $(CFLAGS) -o $@ $<

bonus: $(NAME_B)

clean:
	make clean -C Libft
	rm -f $(OBJFILES) $(OBJBONUS)

fclean:
	make fclean -C Libft
	rm -f $(NAME) $(NAME_B) $(OBJBONUS) $(OBJFILES) ${LIBFT} 

re: fclean all
	
.PHONY: clean fclean all re bonus