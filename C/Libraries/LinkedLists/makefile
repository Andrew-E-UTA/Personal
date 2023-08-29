SRC1 = source.c
SRC2 = linkedlist.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
EXE = s

CFLAGS = -g 

all : $(EXE)

$(EXE): $(OBJ1) $(OBJ2)
	gcc  $(CFLAGS) $(OBJ1) $(OBJ2) -o $(EXE)

$(OBJ1): $(SRC1)
	gcc -c  $(CFLAGS) $(SRC1)

$(OBJ2): $(SRC2)
	gcc -c  $(CFLAGS) $(SRC2)
