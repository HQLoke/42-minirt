# Implicit variables
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I./include -g -fsanitize=address

# source and object files
SRCDIR	=	src
SRCS	=	ft_vec.c
OBJDIR	=	obj
OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# targets
LIBRT	=	librt.a

all: $(LIBRT)

$(OBJDIR):
	@mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(LIBRT): $(OBJS)
	$(AR) crs $@ $?

clean:
	@echo "Removing object files..." 
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Removing libraries"
	@$(RM) $(LIBRT)

re: fclean all

.PHONY: clean
