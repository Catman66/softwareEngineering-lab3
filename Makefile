all: src/*.cpp
	g++ $^ -o build/a.out -Iinclude
	
debug: src/*.cpp
	g++ $^ -g  -Iinclude -DDEBUG -o build/a.out && \
	gdb build/a.out -x scripts/init.gdb


run: src/*
	./build/a.out