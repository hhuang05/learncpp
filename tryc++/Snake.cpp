#include <iostream>
#include <string>
#include "Snake.hpp"
#include "Utilities.hpp"

void Snake::fruitSetUp()
{
  // Update rand seed
  randomNumberSeed();
  
  // Now get the coordinates
  // We limit the possible coordinates to be within the bounding box
  m_fruitPosition.first = randomNumber() % (Snake::border_width-2) + 1;
  m_fruitPosition.second = randomNumber() % (Snake::border_height-2) + 1;
}

// Puts snake in the middle
void Snake::snakeSetUp()
{
  m_headPosition.first = border_width / 2;
  m_headPosition.second = border_height / 2;
}

void Snake::drawGameBoard()
{
  // Draw snake head
  placeXY(m_headPosition.first, m_headPosition.second);
  std::cout << "O";

  // Draw fruit
  placeXY(m_fruitPosition.first, m_fruitPosition.second);
  std::cout << "F";
}

void Snake::drawBorder()
{
  std::string hor_line(Snake::border_width - 2, '*');

  for (int i = 0; i < Snake::border_height; ++i) {
    // Draw left border
    placeXY(0, i);
    std::cout << "*";

    // Draw the top and bottom
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
  drawGameBoard();
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
