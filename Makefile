CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ_DIR = obj
EXEC_DIR = exec

# Path: src/
DEPS_MAIN = $(wildcard src/*.h)
DEPS_TOUCH = $(wildcard src/*.h)


# Path: obj/
OBJ_MINI_GLIBC = $(OBJ_DIR)/mini_memory.o $(OBJ_DIR)/mini_string.o $(OBJ_DIR)/mini_sys.o $(OBJ_DIR)/mini_io.o
OBJ_MAIN = $(OBJ_DIR)/main.o $(OBJ_MINI_GLIBC)
OBJ_TOUCH = $(OBJ_DIR)/mini_touch.o $(OBJ_MINI_GLIBC)
OBJ_CP = $(OBJ_DIR)/mini_cp.o $(OBJ_MINI_GLIBC)
OBJ_ECHO = $(OBJ_DIR)/mini_echo.o $(OBJ_MINI_GLIBC)
OBJ_CAT = $(OBJ_DIR)/mini_cat.o $(OBJ_MINI_GLIBC)
OBJ_HEAD = $(OBJ_DIR)/mini_head.o $(OBJ_MINI_GLIBC)
OBJ_TAIL = $(OBJ_DIR)/mini_tail.o $(OBJ_MINI_GLIBC)
OBJ_CLEAN = $(OBJ_DIR)/mini_clean.o $(OBJ_MINI_GLIBC)
OBJ_GREP = $(OBJ_DIR)/mini_grep.o $(OBJ_MINI_GLIBC)
OBJ_WC = $(OBJ_DIR)/wc.o $(OBJ_MINI_GLIBC)

EXEC = main mini_touch mini_cp mini_echo mini_cat mini_head mini_tail mini_clean mini_grep wc

all: $(OBJ_DIR) $(EXEC_DIR) $(EXEC)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(EXEC_DIR):
	mkdir -p $(EXEC_DIR)

main: $(OBJ_MAIN)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/$@ $^

mini_touch: $(OBJ_TOUCH)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/$@ $^

mini_cp: $(OBJ_CP)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/$@ $^

mini_echo: $(OBJ_ECHO)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/$@ $^

mini_cat: $(OBJ_CAT)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/$@ $^

mini_head: $(OBJ_HEAD)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/$@ $^

mini_tail: $(OBJ_TAIL)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/$@ $^

mini_clean: $(OBJ_CLEAN)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/$@ $^

mini_grep: $(OBJ_GREP)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/$@ $^

wc: $(OBJ_WC)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/$@ $^


$(OBJ_DIR)/%.o: src/%.c $(DEPS_MAIN)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: src/mini_lib/%.c $(DEPS_TOUCH)
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -rf $(OBJ_DIR) $(EXEC_DIR)