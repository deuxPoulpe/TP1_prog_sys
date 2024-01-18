CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ_DIR = obj

# Path: src/
SRC_MAIN = src/main.c
SRC_TOUCH = src/mini_lib/mini_touch.c
SRC_CP = src/mini_lib/mini_cp.c
SRC_ECHO = src/mini_lib/mini_echo.c
DEPS_MAIN = $(wildcard src/*.h)
DEPS_TOUCH = $(wildcard src/*.h)


# Path: obj/
OBJ_MINI_GLIBC = $(OBJ_DIR)/mini_memory.o $(OBJ_DIR)/mini_string.o $(OBJ_DIR)/mini_sys.o $(OBJ_DIR)/mini_io.o
OBJ_MAIN = $(OBJ_DIR)/main.o $(OBJ_MINI_GLIBC)
OBJ_TOUCH = $(OBJ_DIR)/mini_touch.o $(OBJ_MINI_GLIBC)
OBJ_CP = $(OBJ_DIR)/mini_cp.o $(OBJ_MINI_GLIBC)
OBJ_ECHO = $(OBJ_DIR)/mini_echo.o $(OBJ_MINI_GLIBC)


all: $(OBJ_DIR) main mini_touch mini_cp mini_echo

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

main: $(OBJ_MAIN)
	$(CC) $(CFLAGS) -o $@ $^

mini_touch: $(OBJ_TOUCH)
	$(CC) $(CFLAGS) -o $@ $^

mini_cp: $(OBJ_CP)
	$(CC) $(CFLAGS) -o $@ $^

mini_echo: $(OBJ_ECHO)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: src/%.c $(DEPS_MAIN)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: src/mini_lib/%.c $(DEPS_TOUCH)
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -rf $(OBJ_DIR) main mini_touch