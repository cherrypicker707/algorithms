CC=clang++
CFLAGS=-fdiagnostics-color=always -Wall -g -Iinclude -Llib

SRC_FILES=$(wildcard src/*.cpp)
OBJ_FILES=$(patsubst src/%.cpp, obj/%.o, $(SRC_FILES))
TOOLS_FILES=$(shell find tools -name "*.cpp")
BIN_FILES=$(patsubst tools/%.cpp, bin/%, $(TOOLS_FILES))

all: lib/libalgorithms.so $(BIN_FILES)

bin/%: tools/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $< -lalgorithms

lib/libalgorithms.so: $(OBJ_FILES)
	@mkid -p $(dir $@)
	$(CC) -shared -o $@ $^

obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -fPIC -c -o $@ $^
