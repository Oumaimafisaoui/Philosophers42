SRC = main.c mutex.c utils.c exit.c parse.c philos.c time.c end_all.c
OBJ = $(SRC:.c=.o)

NAME  = philo

all : $(NAME)

$(NAME) : $(OBJ)
	gcc -pthread $(OBJ) -o $(NAME)
	@echo "\033[92mIt compiles !\033[0m"

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME) $(OBJ)
re: fclean all
	rm -f $(NAME) $(OBJ)
.PHONY : all clean fclean re
