all: run

run: link
	./build/sokoban

link: compile
	cmake --build ./build

compile:
	cmake -S . -B ./build

clean:
	rm -rf ./build

