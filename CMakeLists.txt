cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

#-Wall -Werror -Wextra
file(GLOB LIBFT libft/*.c libft/*.h)
set(SOURCES src/fdf.c src/validation.c src/function_point.c src/error.c src/map_creation.c src/ft_atoi_er.c src/free_split.c src/init_window.c src/size_designation.c src/ft_abs.c src/pars_color.c src/draw_map.c src/starting_position.c src/isometric.c src/map_center.c)


add_executable(fdf ${SOURCES} ${LIBFT})
