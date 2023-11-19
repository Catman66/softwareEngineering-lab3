all: src/*.cpp
	g++ $^ -o build/a.out -Iinclude

run: build/a.out	
	./build/a.out