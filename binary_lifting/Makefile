CC=clang++
CFLAGS=-fdiagnostics-color=always -g -Iinclude -Llib

SRC_FILES=$(wildcard src/*.cpp)
BIN_FILES=$(patsubst src/%.cpp, bin/%, $(SRC_FILES))

TESTS_SRC_FILES=$(wildcard tests/src/*.cpp)
TESTS_BIN_FILES=$(patsubst tests/src/%.cpp, tests/bin/%, $(TESTS_SRC_FILES))

.PHONY: all

all: $(BIN_FILES) $(TESTS_BIN_FILES)

bin/%: src/%.cpp lib/libbinary_lifting.a
	$(CC) $(CFLAGS) -o $@ $< -lbinary_lifting

tests/bin/%: tests/src/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

lib/libbinary_lifting.a: bin/binary_lifting/binary_lifting.o
	ar rcs $@ $^

bin/binary_lifting/binary_lifting.o: src/binary_lifting/binary_lifting.cpp
	$(CC) $(CFLAGS) -c -o $@ $^
