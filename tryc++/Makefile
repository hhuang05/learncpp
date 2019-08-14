all: snake
	clang++ -std=c++11 initialize.cpp Snake.o Utilities.o -o snake_game.out

snake: Snake.cpp Snake.hpp util
	clang++ -std=c++11 -c Snake.cpp -o Snake.o

util: Utilities.cpp Utilities.hpp
	clang++ -std=c++11 -c Utilities.cpp -o Utilities.o