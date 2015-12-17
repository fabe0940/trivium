CC = g++
CFLAGS = $(WARNINGS) $(DEBUG) $(DEFINE)
DEBUG = -g
#DEFINE = -DVAR=VAL
WARNINGS = -ansi -pedantic -Wall -Wextra -D__USE_FIXED_PROTOTYPES__
OBJ = main.o
#LIBS = -lncurses
APPLICATION_NAME = trivium

.PHONY : all rebuild clean

all : $(APPLICATION_NAME)

rebuild :
	make clean
	make all

$(APPLICATION_NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(APPLICATION_NAME) $(LIBS)

main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

clean :
	rm -f $(APPLICATION_NAME) $(OBJ)
