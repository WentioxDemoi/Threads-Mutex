SRC =	$(wildcard src/*.c)

NAME = panoramix

NAME_OBJS	=	$(SRC:.c=.o)

all: $(NAME) clean

$(NAME):	$(NAME_OBJS)
	gcc $(SRC) -o $(NAME) -pthread 
	
clean	:
	rm -f $(NAME_OBJS) $(clean)
	

fclean	:	clean
	rm -f $(NAME)
	
	

re	:	fclean all clean

.PHONY: all clean fclean re