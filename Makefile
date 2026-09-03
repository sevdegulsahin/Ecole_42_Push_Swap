NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = push_swap.c \
              ft_split.c \
              parsing_helpers.c \
              stack_utils.c \
			  adaptive_sort.c \
			  calculate_disorder.c \
			  helpers.c \
			  medium_sort.c \
			  push_operations.c \
			  reverse_rotate_operations.c \
			  rotate_operations.c \
			  simple_sort.c \
			  swap_operations.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re