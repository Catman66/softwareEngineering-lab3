all: src/*.cpp
	g++ $^ -o build/a.out -Iinclude
	
debug: src/*.cpp
	g++ $^ -g -o build/a.out -Iinclude &
	gdb build/a.out -x init.gdb


run: all
	./build/a.out