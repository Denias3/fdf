cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
file(GLOB LIBFT libft/*.c libft/*.h)
set(SOURCES src/fdf.c src/validation.c src/function_point.c src/error.c src/ft_atoi_er.c src/free_split.c)


add_executable(fdf ${SOURCES} ${LIBFT})
