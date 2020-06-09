CPP=g++
CPPFLAGS=--std=c++11 -c
OFLAGS=-o ./build/

all: build/app

run:
	 make clean && make && ./build/app

build/app: build/main.o
	 g++ build/*.o -lcurses -o build/app

build/main.o: build/game.o
	 $(CPP) $(CPPFLAGS) main.cpp $(OFLAGS)main.o

build/game.o: build
	 $(CPP) $(CPPFLAGS) src/game.cpp $(OFLAGS)game.o

build:
	 mkdir -p build

clean:
	 rm -rf ./build
