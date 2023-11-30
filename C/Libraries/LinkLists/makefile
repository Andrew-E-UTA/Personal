#Author: Andrew Espinoza
#
#Description: 

SRC = test.c
LIB = list.c
OBJS = $(SRC:.c=.o) $(LIB:.c=.o)
EXE = $(SRC:.c=)


CFLAGS = -Wall

DFALGS = -g


all : $(EXE) clean

$(EXE) : $(OBJS)
	gcc -o $(EXE) $(OBJS) $(CFLAGS) $(DFLAGS)

$(OBJS) :
	gcc -c $(SRC) lib/$(LIB) $(CFLAGS) $(DFLAGS)

clean : 
	rm *.o
