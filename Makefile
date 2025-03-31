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
		exec/libft_utils.c \
		exec/builtins2.c \


OBJS = $(SRCS:.c=.o) $(PARSER_SRCS:.c=.o) $(EXEC_SRC:.c=.o)

INLCUDES = -I.

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LDFLAGS = -lreadline

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INLCUDES) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "Compilation complete"
%.o: %.c
	@$(CC) $(CFLAGS) $(INLCUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Clean complete"

re: fclean all
	@echo "Rebuild complete"

.PHONY: all clean fclean re