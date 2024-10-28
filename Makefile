##
## EPITECH PROJECT, 2024
## lion-engine
## File description:
## Makefile
##

SRC	=	main.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=		 -I./include

LXXDFLAGS = -L./build/ -llion-engine

CC = g++

NAME	=	game

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LXXDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
