NAME = push_swap

SRCS =  push_swap.c  ft_error.c swap.c push.c rotate.c rev_rotate.c

OBJS = $(SRCS:.c=.o)

LIBFTA = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

%.o: %.c
	cc $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFTA) $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBFTA) -o $(NAME) 

$(LIBFTA):
	make -C libft

install:
	python3 -m pip install --upgrade pip setuptools
	python3 -m pip install norminette
	sudo apt install valgrind -y

check:
	norminette $(SRCS)

test: $(LIBFTA)
	gcc -ggdb $(FLAGS) tests/test.c swap.c push.c rotate.c rev_rotate.c tests/unity.c $(LIBFTA) -o result.out

run: clean fclean test
	./result.out

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

valgrind: clean fclean all
	rm -f $(OBJS) $(NAME)
	valgrind --leak-check=full ./result.out

.PHONY: clean fclean all re