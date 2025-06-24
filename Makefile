CC=clang++
CFLAGS=-fdiagnostics-color=always -g

SRC_FILES=$(shell find src -name "*.cpp")
BIN_FILES=$(patsubst src/%.cpp, bin/%, $(SRC_FILES))
LIB_FILES=$(shell find lib -name "*.cpp")
OBJ_FILES=$(patsubst lib/%.cpp, obj/%.o, $(LIB_FILES))

.PHONY: all

all: $(BIN_FILES)

bin/%: src/%.cpp bin/libalgorithms.a
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Iinclude -Lbin -o $@ $< -lalgorithms

bin/libalgorithms.a: $(OBJ_FILES)
	@mkdir -p $(dir $@)
	ar rcs $@ $^

obj/%.o: lib/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Iinclude -c -o $@ $<
