CC=clang++
CFLAGS=-fdiagnostics-color=always -g -Iinclude -Llib

SRC_FILES=$(wildcard src/*.cpp)
OBJ_FILES=$(patsubst src/%.cpp, obj/%.o, $(SRC_FILES))
TOOLS_FILES=$(shell find tools -name "*.cpp")
BIN_FILES=$(patsubst tools/%.cpp, bin/%, $(TOOLS_FILES))

all: $(BIN_FILES)

bin/%: tools/%.cpp lib/libalgorithms.a
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $< -lalgorithms

lib/libalgorithms.a: $(OBJ_FILES)
	@mkdir -p $(dir $@)
	ar rcs $@ $^

obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ -- $^
