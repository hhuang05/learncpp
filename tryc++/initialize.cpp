#include "Snake.hpp"
#include "Utilities.hpp"

int main()
{
  Snake snake_g;

  snake_g.snakeSetUp();
  snake_g.fruitSetUp();
  
  int game_clock = 0;
  while (!snake_g.isGameOver()) {
    if (game_clock > 3) {
      std::cout << "Game Over!\n";
      break;
    }
    snake_g.draw();
    snake_g.input();
    snake_g.logic();
    std::cout << "Game clock " << game_clock << std::endl;
    ++game_clock;
  }

  return 0;
}
