NAME = exec

SRCS = builtins.c \
	libft_utils.c \
	execute_commands.c \
	execute_utils.c \
	executor.c \

PARSER_SRCS = ../parser/libft_utils.c \
			../parser/libft_utils_moar.c \
			../parser/utils.c

OBJS = $(SRCS:.c=.o) $(PARSER_SRCS:.c=.o)


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