NAME = mini_shell
CC = cc -lreadline
RM = rm -f
FLAGS = -Wall -Wextra -Werror 
SRC_1 = parsing/tokenisation.c parsing/utils.c
OBJ_1 = ${SRC_1:.c=.o}
INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1}
	make -C ./libft
	${CC} ${FLAGS} ${OBJ_1} -o ${NAME} ${INCLUDE}
all: ${NAME}

clean:
	${RM} ${OBJ_1} ${NAME}
	@cd ./libft && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd ./libft && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re