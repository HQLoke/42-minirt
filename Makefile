NAME = minirt

CC = gcc
CFLAGS = -g3 -fsanitize=address
#-Wall -Wextra -Werror
RM = rm -f

INCLUDE = -Iincludes -Ilibft
LIBFT_PATH = ./libft
LIBRARY = -Llibft -lft

MAIN = main.c
ERROR_DIR = ./srcs/error/
SRCS = $(addprefix $(ERROR_DIR), check_objects.c check_settings.c error_handler.c error_utils.c)
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@make re -C ${LIBFT_PATH}
	@${CC} ${CFLAGS} ${INCLUDE} -o ${NAME} ${MAIN} ${OBJS} ${LIBRARY}

%.o: %.c
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean:
	@${RM} ${OBJS}
	@make clean -C ${LIBFT_PATH}

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: all clean fclean re
.SILENT: all clean fclean re