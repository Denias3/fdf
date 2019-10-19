NAME = libft.a
FILEC = *.c

FILEO = *.o

LIB = libft.h

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FILEC)
	@gcc $(FLAG) -c $(FILEC) -I $(LIB)
	@ar rc $(NAME) $(FILEO)
	@ranlib $(NAME)
	@echo "-> compil libft"

clean:
	@rm -rf $(FILEO)
	@echo "-> clean libft"

fclean: clean
	@rm -rf $(NAME)
	@echo "-> fclean libft"

re: fclean all