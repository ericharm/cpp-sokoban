CPP=g++
CPPFLAGS=--std=c++11 -c -g
OFLAGS=-o ./build/

# app

all: build/app

run:
	make clean && make build/app && ./build/app

build/app: build/main.o
	$(CPP) build/*.o -lcurses -o build/app

build/main.o: build/main_menu.o build/state_stack.o
	$(CPP) $(CPPFLAGS) main.cpp $(OFLAGS)main.o

build/state_stack.o: build
	$(CPP) $(CPPFLAGS) src/StateStack.cpp $(OFLAGS)state_stack.o

build/main_menu.o: build/game.o build/point.o
	$(CPP) $(CPPFLAGS) src/states/MainMenu.cpp $(OFLAGS)main_menu.o

build/game.o: build/entity.o build/level.o
	$(CPP) $(CPPFLAGS) src/states/Game.cpp $(OFLAGS)game.o

build/level.o: build/entity.o build/player.o build/boulder.o build/collision_manager.o build/screen_position.o
	$(CPP) $(CPPFLAGS) src/Level.cpp $(OFLAGS)level.o

build/collision_manager.o: build/entity.o
	$(CPP) $(CPPFLAGS) src/CollisionManager.cpp $(OFLAGS)collision_manager.o

build/player.o: build/entity.o
	$(CPP) $(CPPFLAGS) src/entities/Player.cpp $(OFLAGS)player.o

build/boulder.o: build/entity.o
	$(CPP) $(CPPFLAGS) src/entities/Boulder.cpp $(OFLAGS)boulder.o

build/entity.o: build build/screen_position.o
	$(CPP) $(CPPFLAGS) src/Entity.cpp $(OFLAGS)entity.o

build/point.o: build
	$(CPP) $(CPPFLAGS) src/Point.cpp $(OFLAGS)point.o

build/screen_position.o: build
	$(CPP) $(CPPFLAGS) src/ScreenPosition.cpp $(OFLAGS)screen_position.o

build/line_and_character_iterator.o: build
	$(CPP) $(CPPFLAGS) src/LineAndCharacterIterator.cpp $(OFLAGS)line_and_character_iterator.o

build:
	mkdir -p build

clean:
	rm -rf ./build

