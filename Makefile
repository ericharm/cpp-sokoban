CPP=g++
CPPFLAGS=--std=c++11 -c -g
OFLAGS=-o ./build/

all: run

run: link
	./build/sokoban

link: compile
	cmake --build ./build

compile:
	cmake -S . -B ./build

clean:
	rm -rf ./build

