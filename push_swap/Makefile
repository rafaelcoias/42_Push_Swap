NAME = push_swap

CHECK = tester

HEAD = ./include

SRC = ./src/main.c ./src/check.c ./src/push.c ./src/swap.c ./src/rotate.c ./src/rv_rotate.c ./src/add.c ./src/get_nbr.c ./src/put_at_top.c ./src/find_nbr.c ./src/sort.c ./src/sort_easy.c ./src/sort_two.c ./src/sort_three.c ./src/sort_five.c ./src/sort_hundreds.c ./src/print_stacks.c 

MAKE_LIBFT = cd ./include/libft && make all

LIBFT_PATH = ./include/libft

OBJ = ${SRC:.c=.o}

GCC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

${NAME}: ${OBJ} 
	${MAKE_LIBFT} -s
	@$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft
	@echo "\n ======= $(GREEN)push_swap created$(RESET) ======= \n"

${CHECK}: ${OBJ}
	${MAKE_LIBFT} -s
	@$(GCC) $(CFLAGS) -o $(CHECK) $(OBJ) -L $(LIBFT_PATH) -lft
	@echo "\n ======= $(GREEN)checker created$(RESET) ======= \n"

# COLORS #
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
RESET       =   \033[0m

# RULES #

all: ${NAME} 

checker: ${CHECK} 

clean:
	@cd ./include/libft && make clean -s
	${RM} ${OBJ}

fclean: clean 
	@cd ./include/libft && make fclean -s
	${RM} ${NAME} ${CHECK}
	@echo "\n ======= $(RED)push_swap removed$(RESET) ======= \n"
	

re:	fclean all

norm:
	@echo "\n ======= $(YELLOW)norm libft$(RESET) ======= \n"
	@cd ./include/libft && norminette -R CheckForbiddenSourceHeader *.c && norminette -R CheckDefine *.h
	@echo "\n ======= $(YELLOW)norm push_swap$(RESET) =======\n "
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c && cd ../include && norminette -R CheckDefine push_swap.h

.PHONY: all checker clean fclean re norm
