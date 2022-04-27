########## 		   NAMES 		##########

NAME = push_swap

CHECK = tester

########## 		  SOURCES 		##########

SRC = ./src/main.c ./src/check.c ./src/push.c ./src/swap.c ./src/rotate.c ./src/rv_rotate.c ./src/add.c ./src/get_nbr.c ./src/put_at_top.c ./src/find_nbr.c ./src/sort.c ./src/sort_easy.c ./src/sort_two.c ./src/sort_three.c ./src/sort_five.c ./src/sort_hundreds.c ./src/print_stacks.c 

########## 		  INCLUDES 		##########

HEAD = ./include

########## 		   LIBFT 		##########

LIBFT = libft

LIBFT_PATH = ./include/libft

########## 		COMPILATION 	##########

OBJ = ${SRC:.c=.o}

CC = gcc

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

########## 		   FLAGS 		##########

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

########## 		   COLORS 		##########

GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
RESET       =   \033[0m

########## 		  COMMANDS		##########

MAKE_LIBFT = cd ${LIBFT_PATH} && make all

CLEAN_LIBFT = cd ${LIBFT_PATH} && make clean -s

FCLEAN_LIBFT = cd ${LIBFT_PATH} && make fclean -s

NORM_LIBFT = cd ${LIBFT_PATH} && norminette -R CheckForbiddenSourceHeader *.c && norminette -R CheckDefine *.h

NORM_PROJECT = cd ./src && norminette -R CheckForbiddenSourceHeader *.c && cd ../include && norminette -R CheckDefine *.h

ECHO = echo

RM = rm -f

########## 		  TARGETS 		##########

${NAME}: ${OBJ} 
	${MAKE_LIBFT} -s
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft

${CHECK}: ${OBJ}
	${MAKE_LIBFT} -s
	$(CC) $(CFLAGS) -o $(CHECK) $(OBJ) -L $(LIBFT_PATH) -lft

########## 		   RULES 		##########

all: ${NAME} 
	${ECHO} "\n<======= $(GREEN)$(NAME) created$(RESET) =======>\n"

checker: ${CHECK}
	${ECHO} "\n<======= $(GREEN)$(CHECK) created$(RESET) =======>\n"

clean:
	${CLEAN_LIBFT}
	${RM} ${OBJ}

fclean: clean 
	${FCLEAN_LIBFT}
	${RM} ${NAME} ${CHECK}
	${ECHO} "\n<======= $(RED)$(NAME) removed$(RESET) ========>\n"
	

re:	fclean all

norm:
	${ECHO} "\n<======= $(YELLOW)Norm $(libft)$(RESET) =======>\n"
	${NORM_LIBFT}
	${ECHO} "\n<======= $(YELLOW)Norm $(NAME)$(RESET) =======>\n "
	${NORM_PROJECT}

.PHONY: all checker clean fclean re norm
