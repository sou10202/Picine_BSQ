NAME = bsq

SRCS = *.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re