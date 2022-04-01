NAME = push_swap

HEAD = ./include

SRC = ./src/main.c ./src/check.c ./src/push.c ./src/swap.c ./src/rotate.c ./src/rv_rotate.c ./src/add_remove.c ./src/get_nbr.c ./src/handle_sort_a.c ./src/handle_sort_b.c ./src/print_stack.c ./src/sort.c ./src/sort_two.c ./src/sort_three.c ./src/sort_five.c ./src/sort_hundreds.c

MAKE_LIBFT = cd ./include/libft && make all

LIBFT_PATH = ./include/libft

OBJ = ${SRC:.c=.o}

GCC = gcc

CFLAGS = -Wall -Wextra -Werror -g 

RM = rm -f

${NAME}: ${OBJ}
	${MAKE_LIBFT} -s
	@$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft
	@echo "\n ======= push_swap created ======= \n"

# RULES #

all: ${NAME}

clean:
	@cd ./include/libft && make clean -s
	${RM} ${OBJ}

fclean: clean
	@cd ./include/libft && make fclean -s
	${RM} ${NAME}
	@echo "\n ======= push_swap removed ======= \n"
	

re:	fclean all

norm:
	@echo "\n ======= norm libft ======= \n"
	@cd ./include/libft && norminette -R CheckForbiddenSourceHeader *.c && norminette -R CheckDefine *.h
	@echo "\n ======= norm push_swap =======\n "
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c && cd ../include && norminette -R CheckDefine *.h

.PHONY: all clean fclean re norm
