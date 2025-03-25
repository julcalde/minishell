NAME =	parser

SRCS =	main.c \
		exeggcute_utils.c \
		exeggutor.c \
		init.c \
		input.c \
		libft_utils.c \
		libft_utils_moar.c \
		loop.c \
		parser.c \
		signals.c \
		tokenizer.c \
		utils.c

OBJS =	$(SRCS:.c=.o)

INLCUDES =	-I.

CC =	gcc
CFLAGS =	-Wall -Wextra -Werror -g
LDFLAGS =	-lreadline

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