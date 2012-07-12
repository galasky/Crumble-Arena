
NAME		=	crumble-arena

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
