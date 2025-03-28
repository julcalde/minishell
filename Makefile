NAME = minishell

SRCS = main.c loop.c
PARSER_SRCS = parser/init.c \
			parser/input.c \
			parser/libft_utils.c \
			parser/libft_utils_moar.c \
			parser/parser.c \
			parser/signals.c \
			parser/tokenizer.c \
			parser/utils.c

EXEC_SRC = exec/builtins.c \
		exec/execute_commands.c \
		exec/execute_utils.c \
		exec/executor.c \


OBJS = $(SRCS:.c=.o) $(PARSER_SRCS:.c=.o) $(EXEC_SRC:.c=.o)

INLCUDES = -I.

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
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