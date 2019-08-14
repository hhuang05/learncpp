all: snake
	clang++ -g -std=c++14 initialize.cpp Snake.o Utilities.o -o snake_game.out

snake: Snake.cpp Snake.hpp util
	clang++ -g -std=c++14 -c Snake.cpp -o Snake.o

util: Utilities.cpp Utilities.hpp
	clang++ -g -std=c++14 -c Utilities.cpp -o Utilities.o