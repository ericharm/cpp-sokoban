CPP=g++
CPPFLAGS=--std=c++11 -c
OFLAGS=-o ./build/

all: build/app

run:
	 make clean && make && ./build/app -Wall -g

build/app: build/main.o
	 g++ build/*.o -lcurses -o build/app

build/main.o: build/game.o
	 $(CPP) $(CPPFLAGS) main.cpp $(OFLAGS)main.o

build/game.o: build/tile.o build/player.o
	 $(CPP) $(CPPFLAGS) src/states/Game.cpp $(OFLAGS)game.o

build/player.o: build/entity.o
	 $(CPP) $(CPPFLAGS) src/entities/Player.cpp $(OFLAGS)player.o

build/tile.o: build/entity.o
	 $(CPP) $(CPPFLAGS) src/entities/Tile.cpp $(OFLAGS)tile.o

build/entity.o: build
	 $(CPP) $(CPPFLAGS) src/Entity.cpp $(OFLAGS)entity.o

build:
	 mkdir -p build

clean:
	 rm -rf ./build
