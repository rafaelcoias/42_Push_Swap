NAME = push_swap

HEAD = push_swap.h

SRC = ./src/main.c ./src/check.c ./src/push.c ./src/swap.c ./src/rotate.c ./src/rv_rotate.c ./src/add_remove.c ./src/get_nbr.c ./src/sort.c ./src/handle_sort.c ./src/handle_sort2.c

LIBFT = ./libft/libft.a

OBJ = ${SRC:.c=.o}

GCC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address 

RM = rm -f

AR = ar rc

RANLIB = ranlib 

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}
	${RANLIB} ${NAME}

# RULES #

all: ${NAME}

clean: 
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re:	fclean all

norm:	
	norminette -R CheckForbiddenSourceHeader *.c
	norminette -R CheckDefine *.h

.PHONY: all clean fclean re norm