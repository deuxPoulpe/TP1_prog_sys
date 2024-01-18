# Variables
CC = gcc
CFLAGS = -Wall 
SRC_DIR = src
OBJ = main.o mini_sys.o mini_string.o mini_memory.o mini_io.o
EXEC = main

# Rules
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

main.o: $(SRC_DIR)/main.c $(SRC_DIR)/mini_lib.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c

mini_sys.o: $(SRC_DIR)/mini_sys.c $(SRC_DIR)/mini_lib.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mini_sys.c

mini_string.o: $(SRC_DIR)/mini_string.c $(SRC_DIR)/mini_lib.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mini_string.c

mini_memory.o: $(SRC_DIR)/mini_memory.c $(SRC_DIR)/mini_lib.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mini_memory.c

mini_io.o: $(SRC_DIR)/mini_io.c $(SRC_DIR)/mini_lib.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mini_io.c

clean:
	rm -f $(OBJ) $(EXEC)
