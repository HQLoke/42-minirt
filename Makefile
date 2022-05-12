NAME = minirt

CC = gcc
CFLAGS = #-g3 -fsanitize=address
#-Wall -Wextra -Werror
RM = rm -f

INCLUDE = -Iincludes -Ilibft
LIBFT_PATH = ./libft
LIBRARY = -Llibft -lft

MAIN = main.c
ERROR_DIR = ./srcs/error/
UTILS_DIR = ./srcs/utils/
SRCS = $(addprefix $(ERROR_DIR), check_objects.c check_settings.c error_handler.c error_utils.c) \
       $(addprefix $(UTILS_DIR), ft_array_size.c ft_memdel.c)
OBJS = ${SRCS:.c=.o}

#Color and format
BOLD = \e[1m
PURPLE = \e[1;35m
GREEN = \e[1;32m
PINK_TEXT = \e[38;2;255;124;212m
NEWLINE = \e[1K\r

all: ${NAME}

${NAME}: ${OBJS}
	@make re -C ${LIBFT_PATH} -s
	@${CC} ${CFLAGS} ${INCLUDE} -o ${NAME} ${MAIN} ${OBJS} ${LIBRARY}
	@printf "$(NEWLINE)$(GREEN)Successfully created $(GREEN)$@$(GREEN)!\n$(NO_COLOR)"

%.o: %.c
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@printf "$(NEWLINE)Creating object file $@ from $<"

clean:
	@${RM} ${OBJS}
	@make clean -C ${LIBFT_PATH} -s

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ${LIBFT_PATH} -s

re: fclean all

.PHONY: all clean fclean re