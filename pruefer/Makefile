CC=clang++
CFLAGS=-fdiagnostics-color=always -g -Iinclude -Llib

SRC_FILES=$(wildcard src/*.cpp)
BIN_FILES=$(patsubst src/%.cpp, bin/%, $(SRC_FILES))

TESTS_SRC_FILES=$(wildcard tests/src/*.cpp)
TESTS_BIN_FILES=$(patsubst tests/src/%.cpp, tests/bin/%, $(TESTS_SRC_FILES))

.PHONY: all tests

all: $(BIN_FILES) tests

tests: $(TESTS_BIN_FILES)

bin/%: src/%.cpp lib/libpruefer.a
	$(CC) $(CFLAGS) -o $@ $< -lpruefer

lib/libpruefer.a: bin/pruefer/pruefer.o bin/pruefer/tree.o
	ar rcs $@ $^

bin/pruefer/%.o: src/pruefer/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

tests/bin/%: tests/src/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean_valgrind:
	rm vgcore.*
