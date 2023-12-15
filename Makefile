# make a make file to compile main.c and mini_lib.c

# Variables
CC = gcc
CFLAGS = -Wall 
OBJ = main.o mini_sys.o mini_string.o mini_memory.o mini_io.o
EXEC = main

# Rules
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

main.o: main.c mini_lib.h 
	$(CC) $(CFLAGS) -c main.c

mini_sys.o: mini_sys.c mini_lib.h
	$(CC) $(CFLAGS) -c mini_sys.c

mini_string.o: mini_string.c mini_lib.h
	$(CC) $(CFLAGS) -c mini_string.c

mini_memory.o: mini_memory.c mini_lib.h
	$(CC) $(CFLAGS) -c mini_memory.c

mini_io.o: mini_io.c mini_lib.h
	$(CC) $(CFLAGS) -c mini_io.c


clean:
	rm -f $(OBJ) $(EXEC)
