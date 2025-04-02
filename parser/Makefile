NAME =	parser

SRCS =	main.c \
		cleaner.c \
		exeggcute_utils.c \
		exeggutor.c \
		init.c \
		input.c \
		libft_utils.c \
		libft_utils_moar.c \
		libft_utils_moaar.c \
		loop.c \
		parser.c \
		quote_handler.c \
		signals.c \
		syntax_checker.c \
		syntax_utils.c \
		tokenizer_checker.c \
		tokenizer_utils.c \
		tokenizer.c \
		utils.c \
		var_expansion.c \
		var_utils.c

OBJS =	$(SRCS:.c=.o)

INLCUDES =	-I.

CC =	gcc
CFLAGS =	-Wall -Wextra -Werror -g
LDFLAGS =	-L/usr/local/opt/readline//lib -lreadline -lhistory

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