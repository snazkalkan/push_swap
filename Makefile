NAME = push_swap
SRCS = push_swap.c utilis.c libft_essentials/lists.c libft_essentials/mandatory.c rotate_rev.c swap_push.c
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
OBJS= $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	$(MAKE) clean
	# clear

all: $(NAME)

clean:
	rm -rf $(OBJS)
re:
	rm -rf $(NAME)
	$(MAKE) all
fclean:
	rm -rf $(NAME)

.phony: all clean fclean