NAME = fdf

FLAGS = -Wall -Werror -Wextra

SRC = fdf.c\
		validation.c\
		error.c\
		function_point.c\
		map_creation.c\
		free_split.c\
		ft_atoi_er.c\
		init_window.c\
		ft_abs.c\
		starting_position.c\
		size_designation.c\
		draw_map.c\
		pars_color.c\
		isometric.c\
		key_press.c\
		distance_approach.c\
		shift.c\
		\
		debag.c


DIRSRC = src

DIRO = obj

DS = $(addprefix $(DIRSRC)/, $(SRC))

OBJ = $(addprefix $(DIRO)/, $(SRC:.c=.o))

INCLUDES = -I libft -I include

LIB_INC = -L libft -lft

all: $(NAME)

$(NAME): libmake creatdiro $(OBJ)
	@gcc $(FLAGS) $(INCLUDES) $(LIB_INC) $(OBJ) -o $(NAME) -L minilibx/ -lmlx -framework OpenGL -framework AppKit
	@echo "-> compil fdf"

$(addprefix $(DIRO)/, %.o): $(addprefix $(DIRSRC)/,%.c)
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

creatdiro:
	@mkdir -p $(DIRO)
	@echo "-> add dir obj"

libmake:
	@make -C libft

clean:
	@rm -rf $(DIRO)
	@make clean -C libft
	@echo "-> clean fdf"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "-> fclean fdf"

re: fclean all
	@echo "-> re fdf"