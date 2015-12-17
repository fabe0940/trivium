CC = gcc
CFLAGS = $(WARNINGS) $(DEBUG) $(DEFINE)
DEBUG = -g
DEFINE = -DDEBUG
#DEFINE = -DTRACE
WARNINGS = -ansi -pedantic -Wall -Wextra -D__USE_FIXED_PROTOTYPES__ --std=c89
OBJ = main.o lfsr.o util.o varArray.o
#LIBS = -lncurses
APPLICATION_NAME = trivium

.PHONY : all rebuild clean

all : $(APPLICATION_NAME)

rebuild :
	make clean
	make all

$(APPLICATION_NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(APPLICATION_NAME) $(LIBS)

main.o : main.c lfsr.h util.h
	$(CC) $(CFLAGS) -c main.c $(LIBS)

lfsr.o : lfsr.c lfsr.h util.h
	$(CC) $(CFLAGS) -c lfsr.c $(LIBS)

util.o : util.c util.h
	$(CC) $(CFLAGS) -c util.c $(LIBS)

varArray.o : varArray.c varArray.h util.h
	$(CC) $(CFLAGS) -c varArray.c $(LIBS)

clean :
	rm -f $(APPLICATION_NAME) $(OBJ)
