#include "Snake.hpp"
#include "Utilities.hpp"

int main()
{
  Snake snake_g;

  snake_g.snakeSetUp();
  snake_g.fruitSetUp();
  
  int game_clock = 0;
  while (!snake_g.isGameOver()) {
    
    snake_g.draw();
    snake_g.input();
    snake_g.logic();
    if (game_clock > 3) {
      placeXY(0, Snake::border_height + 1);
      std::cout << "Game Over! "
		<< "Game clock " << game_clock << std::endl;
      break;
    }

    ++game_clock;
  }
  
  return 0;
}
