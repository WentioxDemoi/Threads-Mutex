SRC =	$(wildcard src/*.c)

NAME = panoramix

NAME_OBJS	=	$(SRC:.c=.o)

all: $(NAME) clean

$(NAME):	$(NAME_OBJS)
	gcc $(SRC) -o $(NAME) -pthread 
	
clean	:
	rm -f $(NAME_OBJS)
	

fclean	:	clean
	rm -f $(NAME)
	
	

re	:	fclean all

# Indique au CMAKE que ces cibles sont uniquement 
# des commandes à exécuter et non des fichiers à compiler
.PHONY: all clean fclean re