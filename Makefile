CPP=g++
CPPFLAGS=--std=c++11 -c -g
OFLAGS=-o ./build/

all: build/app

run:
	 make clean && make && ./build/app

build/app: build/main.o
	 g++ build/*.o -lcurses -o build/app

build/main.o: build/game.o
	 $(CPP) $(CPPFLAGS) main.cpp $(OFLAGS)main.o

build/game.o: build/entity.o
	 $(CPP) $(CPPFLAGS) src/states/Game.cpp $(OFLAGS)game.o

build/entity.o: build
	 $(CPP) $(CPPFLAGS) src/Entity.cpp $(OFLAGS)entity.o

build:
	 mkdir -p build

clean:
	 rm -rf ./build
