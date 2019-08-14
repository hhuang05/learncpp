#include <iostream>
#include <string>
#include "Snake.hpp"
#include "Utilities.hpp"

void Snake::fruitSetUp()
{
  // Now get the coordinates
  // We limit the possible coordinates to be within the bounding box
  m_fruitPosition.first = randomNumber() % (Snake::border_width-2) + 1;
  m_fruitPosition.second = randomNumber() % (Snake::border_height-2) + 1;

  if (m_fruitPosition.first == m_headPosition.first && 
      m_fruitPosition.second == m_headPosition.second) {
    fruitSetUp();
  }
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

  // After drawing fruit, set cursor to end of board
  placeXY(0, Snake::border_height + 1);
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
  std::cout << std::flush;
}

Snake::Direction Snake::input()
{
  char input_ch = getChar();

  switch (input_ch) 
  {
    case 'w':
      return Snake::Direction::UP;
    case 'a':
      return Snake::Direction::LEFT;
    case 's':
      return Snake::Direction::DOWN;
    case 'd':
      return Snake::Direction::RIGHT;
    default:
      return Snake::Direction::STOPPED;
  }
}

void Snake::logic()
{
  Snake::Direction new_dir = input();
  switch (new_dir) 
  {
    case Snake::Direction::UP :
      moveUp();
      break;

    case Snake::Direction::LEFT :
      moveLeft();
      break;

    case Snake::Direction::DOWN :
      moveDown();
      break;

    case Snake::Direction::RIGHT :
      moveRight();
      break;

    default:
      break;
  }
}

void Snake::moveLeft()
{
  if (m_headPosition.first > 1) {
    m_headPosition.first--;
  } else if (m_headPosition.first == 1) {
    m_headPosition.first = Snake::border_width - 2;
  }
}

void Snake::moveRight()
{
  if (m_headPosition.first < (Snake::border_width-2)) {
    m_headPosition.first++;
  } else if (m_headPosition.first == (Snake::border_width-2)) {
    m_headPosition.first = 1 ;
  }
}

void Snake::moveUp()
{
  std::cerr << "Go Up\n";
}

void Snake::moveDown()
{
  std::cerr << "Go Down\n";
}
