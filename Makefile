NAME = minirt

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -f

INCLUDE = -Iinclude -Ilibft
LIBFT_PATH = ./libft
LIBRARY = -Llibft -lft

MAIN = main.c
SRCS = 
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	make re -C ${LIBFT_PATH}
	${CC} ${CFLAGS} ${INCLUDE} -o ${NAME} ${MAIN} ${OBJS} ${LIBRARY}

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean:
	${RM} ${OBJS}
	make clean -C ${LIBFT_PATH}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: all clean fclean re