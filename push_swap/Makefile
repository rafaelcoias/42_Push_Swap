########## 		   NAMES 		##########

NAME = push_swap

CHECK = checker

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

RM = rm -f

########## 		  MESSAGES 		##########

CREATE_PROJ_MSG = @echo "\n<========== $(GREEN)$(NAME) created$(RESET) ==========>\n"

CREATE_BONUS_MSG = @echo "\n<========== $(GREEN)$(CHECK) created$(RESET) ==========>\n"

REMOVED_MSG = @echo "\n<========== $(RED)$(NAME) removed$(RESET) ==========>\n"

NORM_LIBFT_MSG = @echo "\n<========== $(YELLOW)Norm $(LIBFT)$(RESET) ==========>\n"

NORM_PROJ_MSG = @echo "\n<========== $(YELLOW)Norm $(NAME)$(RESET) ==========>\n"

########## 		  TARGETS 		##########

${NAME}: ${OBJ} 
	${MAKE_LIBFT} -s
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft

${CHECK}: ${OBJ}
	${MAKE_LIBFT} -s
	$(CC) $(CFLAGS) -o $(CHECK) $(OBJ) -L $(LIBFT_PATH) -lft

########## 		   RULES 		##########

all: ${NAME} 
	${CREATE_PROJ_MSG}

bonus: ${CHECK}
	${CREATE_BONUS_MSG}

clean:
	${CLEAN_LIBFT}
	${RM} ${OBJ}

fclean: clean 
	${FCLEAN_LIBFT}
	${RM} ${NAME} ${CHECK}
	${REMOVED_MSG}
	

re:	fclean all

norm:
	${NORM_LIBFT_MSG}
	@cd ${LIBFT_PATH} && norminette -R CheckForbiddenSourceHeader *.c && norminette -R CheckDefine *.h
	${NORM_PROJ_MSG}
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c && cd ../include && norminette -R CheckDefine *.h

.PHONY: all bonus clean fclean re norm
