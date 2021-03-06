#include "Snake.hpp"
#include "Utilities.hpp"

int main()
{
  // Update rand seed
  randomNumberSeed();
  
  Snake snake_g;  
  int game_clock = 0;

  while (!snake_g.isGameOver()) {
    
    snake_g.draw();
    snake_g.logic();
    if (game_clock > 3) {
      placeXY(0, Snake::border_height + 4);
      std::cout << "Game Over! "
		<< "Game clock " << game_clock << std::endl;
      //break;
    }

    ++game_clock;
  }
  
  return 0;
}
