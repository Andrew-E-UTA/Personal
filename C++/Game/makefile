SRC1 = source.cpp
SRC2 = Game.cpp
SRC3 = Entity.cpp
SRC4 = Vec2.cpp


OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)
OBJ4= $(SRC4:.cpp=.o)	

OBJ_FILES = $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)

SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

EXE = Asteroids

.PHONY : clean


all : $(EXE) clean

$(EXE) : $(OBJ_FILES)
	g++ -o $(EXE) $(OBJ_FILES) $(SFML_LIBS)

$(OBJ_FILES) : $(SRC1) $(SRC2) $(SRC3) $(SRC4)
	g++ -c $(SRC1) $(SRC2) $(SRC3) $(SRC4)

clean:
	rm *.o

