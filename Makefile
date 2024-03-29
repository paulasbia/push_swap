NAME = push_swap

SRCS =  ./srcs/push_swap.c ./srcs/ft_error.c ./srcs/check_sorted.c ./srcs/swap.c ./srcs/push.c ./srcs/rotate.c ./srcs/rev_rotate.c \
		./srcs/ft_sort.c ./srcs/ft_rotate_type.c ./srcs/cases_utils_ab.c ./srcs/find_utils.c ./srcs/apply_utils.c ./srcs/cases_utils_ba.c 

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
	python3 -m norminette $(SRCS)

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
	valgrind --leak-check=full ./push_swap 6 5 4 3 2 1 7 0 29 7
	rm -f $(OBJS) $(NAME)

test_ex:
	./push_swap 8 2 7 1 6 4 5 3
	./push_swap 2 4 5 3 1

.PHONY: clean fclean all re