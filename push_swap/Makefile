NAME = push_swap

HEAD = ./include/push_swap.h

SRC = ./src/main.c ./src/check.c ./src/push.c ./src/swap.c ./src/rotate.c ./src/rv_rotate.c ./src/add_remove.c ./src/get_nbr.c ./src/sort.c ./src/handle_sort.c ./src/handle_sort2.c

LIBFT = $(LIBFT_PATH)/libft.a

LIBFT_PATH = ./include/libft

MAKE_LIBFT = cd ./include/libft && make all

OBJ = ${SRC:.c=.o}

GCC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -f

${NAME}: ${OBJ}
	@${MAKE_LIBFT} -s
	@$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft
	@echo " === push_swap created === "

# RULES #

all: ${NAME}

clean:
	@cd ./include/libft && make clean -s
	${RM} ${OBJ}

fclean: clean
	@cd ./include/libft && make fclean -s
	${RM} ${NAME}
	@echo " === push_swap removed === "

re:	fclean all

norm:
	@echo "======= norm libft ======="
	@cd ./include/libft && norminette -R CheckForbiddenSourceHeader *.c && norminette -R CheckDefine *.h
	@echo "======= norm push_swap ======="
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c && cd ../include && norminette -R CheckDefine *.h 

.PHONY: all clean fclean re norm
