NAME = exec

SRCS = libft_utils.c tokenization.c main.c

OBJS = $(SRCS:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lreadline

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INLCUDES) $(OBJS) -o $(NAME) $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) $(INLCUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re