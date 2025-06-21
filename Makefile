CC=clang++
CFLAGS=-fdiagnostics-color=always

SRC_FILES=$(shell find src -name "*.cpp")
BIN_FILES=$(patsubst src/%.cpp, bin/%, $(SRC_FILES))
LIB_FILES=$(shell find lib -name "*.cpp")
OBJ_FILES=$(patsubst lib/%.cpp, obj/%.o, $(LIB_FILES))

.PHONY: all

all: $(BIN_FILES)

bin/%: src/%.cpp bin/libalgorithms.a
	$(CC) $(CFLAGS) -Iinclude -Lbin -o $@ $< -lalgorithms

bin/libalgorithms.a: $(OBJ_FILES)
	ar rcs $@ $^

obj/%.o: lib/%.cpp
	$(CC) $(CFLAGS) -Iinclude -c -o $@ $<
