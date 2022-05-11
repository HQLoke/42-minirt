# Implicit variables
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I../include -g -fsanitize=address
LDFLAGS	=	-L.. -L../libft
LDLIBS	=	-lrt -lft -lm
SRCS	=	$(wildcard test*.c)
MAINS	=	$(SRCS:test_ft_%.c=%)

all: $(MAINS)

librt:
	make --no-print-directory -C .. librt.a

%: test_ft_%.c librt
	@$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)
	@echo Testing $<:
	@./$@
	@$(RM) $@

clean:
	@echo "Removing test executables..."
	$(RM) $(MAINS)

fclean: clean
	@$(MAKE) --no-print-directory -C .. fclean

re: fclean all

norm:
	norminette *.c

.PHONY: clean librt norm
