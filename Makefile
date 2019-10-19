NAME = fdf

SRC = src/fdf.c

INCLUDES = libft/libft.a

all: $(NAME)

$(NAME): $(SRC)
		@make -C libft
		gcc -Wall -Werror -Wextra -g $(SRC) $(INCLUDES) -o $(NAME)
		@echo "-> compil fdf"

clean:
		@make clean -C libft
		@echo "-> clean fdf"
fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)
		@echo "-> fclean fdf"

re: fclean all
		@echo "-> re fdf"