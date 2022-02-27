NAME = push_swap

HEAD = push_swap.h

SRC = ./main.c ./check.c ./push.c ./swap.c ./rotate.c ./rv_rotate.c ./add_remove.c ./get_nbr.c ./sort.c

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