# Implicit variables
CC		=	gcc
INCLUDE	=	-Iinclude -Ilibft
CFLAGS	=	-Wall -Wextra -Werror $(INCLUDE) -g3 -fsanitize=address
FDFLAGS	=	-L. -Llibft
FDLIBS	=	-lrt -lft

# source and object files
ELEMENT_DIR	=	element/
ERROR_DIR	=	error/
IMAGE_DIR	=	image/
LINALG_DIR	=	linalg/
TRACE_DIR	=	trace/
UTILS_DIR	=	utils/

SRCDIR	=	src
SRCS	=	$(addprefix $(ELEMENT_DIR), \
				ft_ambient.c \
				ft_camera.c \
				ft_checkerboard.c \
				ft_cone.c \
				ft_cylinder.c \
				ft_light.c \
				ft_obj.c \
				ft_plane.c \
				ft_point.c \
				ft_ray.c \
				ft_sphere.c \
				ft_spot.c \
			) \
			$(addprefix $(ERROR_DIR), \
				check_objects.c \
				check_settings.c \
				error_handler.c \
				error_utils.c \
			) \
			$(addprefix $(IMAGE_DIR), \
				ft_image.c \
				ft_image8.c \
				ppm_maker.c \
			) \
			$(addprefix $(LINALG_DIR), \
				ft_affine_transform.c \
				ft_affine.c \
				ft_mat.c \
				ft_mat_mul.c \
				ft_mat_op.c \
				ft_math.c \
				ft_vec.c \
				ft_vec_mul.c \
				ft_vec_new.c \
				ft_vec_op.c \
			) \
			$(addprefix $(TRACE_DIR), \
				ft_hit.c \
				ft_phong.c \
				ft_trace.c \
			) \
			$(addprefix $(UTILS_DIR), \
				ft_array_size.c \
				ft_atof.c \
				ft_memdel.c \
			)
OBJDIR	=	obj
OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:%.c=%.o))

# targets
MAIN	=	main.c
NAME	=	minirt
LIBRT	=	librt.a

LIBFT_PATH = ./libft

# colour and format
BOLD = \e[1m
PURPLE = \e[1;35m
GREEN = \e[1;32m
PINK_TEXT = \e[38;2;255;124;212m
NEWLINE = \e[1K\r

all: $(NAME)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT_PATH)/libft.a $(LIBRT)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(FDFLAGS) $(FDLIBS)
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

test:
	@gcc  -g3 -fsanitize=address -Iinclude -Ilibft -o 123TEST TEST.c -Llibft -lft
	@./123TEST
	@rm 123TEST

.PHONY: libft clean norm test
