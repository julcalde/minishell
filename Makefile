NAME = minishell

SRCS = main.c handle_input.c libft_tmp.c

OBJS = $(SRCS:.c=.o)

INLCUDES = -I.

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