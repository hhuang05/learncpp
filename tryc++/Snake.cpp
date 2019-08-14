#include <iostream>
#include <string>
#include "Snake.hpp"
#include "Utilities.hpp"

void Snake::fruitSetUp()
{
}

void Snake::snakeSetUp()
{
}

void Snake::drawGameBoard()
{

}

void Snake::drawBorder()
{
  std::string hor_line(Snake::border_width - 2, '*');

  for (int i = 0; i < Snake::border_height; ++i) {
    // Draw left border
    placeXY(0, i);
    std::cout << "*";
    if (i == 0 or i == (Snake::border_height - 1)) {
      std::cout << hor_line;
    } 

    // Draw right border
    placeXY(Snake::border_width - 1, i);
    std::cout << "*";
  }
  std::cout << std::endl;
}

void Snake::draw()
{
  clearScreen();
  drawBorder();
}

void Snake::input()
{
}

void Snake::logic()
{
}

void Snake::moveLeft()
{
}

void Snake::moveRight()
{
}

void Snake::moveUp()
{
}

void Snake::moveDown()
{
}
