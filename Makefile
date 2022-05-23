# Implicit variables
CC		=	gcc
INCLUDE	=	-Iinclude -Ilibft
CFLAGS	=	-Wall -Wextra -Werror $(INCLUDE) -g3 -fsanitize=address
FDFLAGS	=	-L. -Llibft
FDLIBS	=	-lrt -lft

# soruce and object files
ERROR_DIR	=	error/
UTILS_DIR	=	utils/

SRCDIR	=	src
SRCS	=	$(addprefix $(ERROR_DIR),	check_objects.c \
										check_settings.c \
										error_handler.c \
										error_utils.c) \
			$(addprefix $(UTILS_DIR),	ft_array_size.c \
										ft_atof.c \
										ft_atol.c \
										ft_memdel.c)
OBJDIR	=	obj
OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:%.c=%.o))

# targets
MAIN	=	main.c
NAME	=	minirt
LIBRT	=	librt.a

LIBFT_PATH = ./libft

#Color and format
BOLD = \e[1m
PURPLE = \e[1;35m
GREEN = \e[1;32m
PINK_TEXT = \e[38;2;255;124;212m
NEWLINE = \e[1K\r

all: $(NAME)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(OBJDIR):
	@mkdir $@

$(NAME): $(LIBFT_PATH)/libft.a $(LIBRT)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(MAIN) $(FDFLAGS) $(FDLIBS)
	@printf "$(NEWLINE)$(GREEN)Successfully created $(GREEN)$@$(GREEN)!\n$(NO_COLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
	@printf "$(NEWLINE)Creating object file $@ from $<"

$(LIBRT): $(OBJS)
	$(AR) crs $@ $?

clean:
	@echo "Removing object files..." 
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFT_PATH) -s

fclean: clean
	@echo "Removing executables and libraries..."
	@$(RM) $(NAME) $(LIBRT)
	@make fclean -C $(LIBFT_PATH) -s

re: fclean all

norm:
	norminette include/* src/*

.PHONY: libft clean norm
