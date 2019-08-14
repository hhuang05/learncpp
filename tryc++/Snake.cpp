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

void Snake::drawBorder()
{
  std::string hor_line(Snake::border_width, '*');

  for (int i = 0; i < Snake::border_height; ++i) {
    if (i == 0 or i == (Snake::border_height - 1)) {
      std::cout << hor_line << "\n";
    } else {
      
    }
  }
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
