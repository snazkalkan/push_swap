NAME = push_swap
SRCS = push_swap.c utilis.c libft_essentials/lists.c libft_essentials/mandatory.c rotate_rev.c swap_push.c parse.c \
		push_a.c targets.c helper.c libft_essentials/tools.c libft_essentials/funcs.c
CC = cc
FLAGS = -Wall -Wextra -Werror -g
OBJS= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)
re:
	rm -rf $(NAME)
	$(MAKE) all

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean re