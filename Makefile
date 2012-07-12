##
## Makefile for raytracer in /home/teisse_l//Documents/projet/raytracer
## 
## Made by lambert teisserenc-bonesteve
## Login   <teisse_l@epitech.net>
## 
## Started on  Wed Jan 25 01:05:57 2012 lambert teisserenc-bonesteve
## Last update Thu Jul 12 14:07:51 2012 lambert teisserenc-bonesteve
##

NAME		=	crumble

CXXFLAGS	=	-I include/ -Wextra -Wall

LDFLAGS		=	-lsfml-window -lsfml-graphics -lsfml-audio -lm

CC		=	g++
RM		=	rm -fv

SRC		=	src/main.cpp		\
			src/window.cpp		\
			src/map.cpp		\
			src/x_image.cpp		\
			src/player.cpp		\
			src/deplacement.cpp	\
			src/colision.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
