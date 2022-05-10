# Implicit variables
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I../include -g -fsanitize=address
SRCS	=	$(wildcard test*.c)
MAINS	=	$(SRCS:test_ft_%.c=%)

# Libraries
LIBRT	=	../librt.a

all: $(MAINS)

$(LIBRT):
	@$(MAKE) --no-print-directory -C .. librt.a

%: test_ft_%.c $(LIBRT)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $< $(LIBRT) -o $@
	@echo Testing $<:
	@./$@
	@$(RM) $@

clean:
	@echo "Removing test executables..."
	$(RM) $(MAINS)

fclean: clean
	@$(MAKE) --no-print-directory -C .. fclean

re: fclean all

.PHONY: clean
