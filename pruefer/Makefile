CC=clang++

.PHONY: all

all: bin/encode bin/decode bin/generate_random_tree

bin/encode: src/encode.cpp lib/libpruefer.a
	$(CC) -fdiagnostics-color=always -g -Iinclude -Llib -o $@ $< -lpruefer

bin/decode: src/decode.cpp lib/libpruefer.a
	$(CC) -fdiagnostics-color=always -g -Iinclude -Llib -o $@ $< -lpruefer

bin/generate_random_tree: src/generate_random_tree.cpp lib/libpruefer.a
	$(CC) -fdiagnostics-color=always -g -Iinclude -Llib -o $@ $< -lpruefer

lib/libpruefer.a: bin/pruefer.o bin/conversion.o
	ar rcs $@ $^

bin/pruefer.o: src/pruefer.cpp
	$(CC) -fdiagnostics-color=always -g -Iinclude -c -o $@ $^

bin/conversion.o: src/conversion.cpp
	$(CC) -fdiagnostics-color=always -g -Iinclude -c -o $@ $^
