# make a make file to compile main.c and mini_lib.c

# Variables
CC = gcc
CFLAGS = -Wall 
OBJ = main.o mini_lib.o
EXEC = main

# Rules
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

main.o: main.c mini_lib.h
	$(CC) $(CFLAGS) -c main.c

mini_lib.o: mini_lib.c mini_lib.h
	$(CC) $(CFLAGS) -c mini_lib.c

clean:
	rm -f $(OBJ) $(EXEC)
