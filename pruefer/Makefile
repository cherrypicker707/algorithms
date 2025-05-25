CC=clang++
CFLAGS=-fdiagnostics-color=always -g -Iinclude -Llib

SRC_FILES=$(wildcard src/*.cpp)
BIN_FILES=$(patsubst src/%.cpp, bin/%, $(SRC_FILES))

.PHONY: all

all: $(BIN_FILES)

bin/%: src/%.cpp lib/libpruefer.a
	$(CC) $(CFLAGS) -o $@ $< -lpruefer

lib/libpruefer.a: bin/pruefer/pruefer.o bin/pruefer/tree.o
	ar rcs $@ $^

bin/pruefer/%.o: src/pruefer/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^
