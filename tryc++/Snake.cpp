#include <iostream>
#include <memory>
#include <deque>
#include <string>
#include <utility>
#include "Snake.hpp"
#include "Utilities.hpp"

class SnakeImpl
{
private:
  typedef std::deque< std::pair<int, int> > tail_deque;
  bool m_gameOver;
  int m_score;
  std::unique_ptr<tail_deque> m_tailPtr;

  // Keep track of last pos of the tail
  std::pair<int, int> m_lastTailPos;
  std::pair<int, int> m_fruitPosition;

  Snake::Direction input();
  void snakeSetUp();
  void fruitSetUp();

  void growSnake(int x, int y);
  void drawGameBoard();
  void drawBorder();
  void drawScore();
  void drawSnake();

public:
  SnakeImpl(): 
    m_gameOver(false), 
    m_score(0),
    m_tailPtr(std::make_unique<tail_deque>()),
    m_fruitPosition(std::make_pair(0,0))
  {
    snakeSetUp();
    fruitSetUp();
  };

  ~SnakeImpl();
  void draw();
  void logic();
  bool isGameOver() { return m_gameOver; }; 
  bool hasCollidedWithTail();
  bool hasEatenFruit();
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();
};

SnakeImpl::~SnakeImpl()
{
}

void SnakeImpl::growSnake(int x, int y)
{
  m_tailPtr->emplace_back(std::make_pair(x, y));
}

void SnakeImpl::fruitSetUp()
{
  // Now get the coordinates
  // We limit the possible coordinates to be within the bounding box
  m_fruitPosition.first = randomNumber() % (Snake::border_width-2) + 1;
  m_fruitPosition.second = Snake::border_height / 2;

  // m_fruitPosition.first = randomNumber() % (Snake::border_width-2) + 1;
  // m_fruitPosition.second = randomNumber() % (Snake::border_height-2) + 1;

  if (m_fruitPosition.first == m_tailPtr->front().first && 
      m_fruitPosition.second == m_tailPtr->front().second) {
    fruitSetUp();
  }
}

void SnakeImpl::snakeSetUp()
{
  growSnake(Snake::border_width / 2, Snake::border_height / 2);
}

void SnakeImpl::drawSnake()
{
  int c = 0;
  for (auto &pair : *m_tailPtr) {
    placeXY(pair.first, pair.second);
    if (c == 0) {
      std::cout << "O";
    } else {
      std::cout << "o";
    }
    ++c;
  }
}

void SnakeImpl::drawGameBoard()
{
  // Draw fruit
  placeXY(m_fruitPosition.first, m_fruitPosition.second);
  std::cout << "F";

  drawSnake();

  // After drawing fruit, set cursor to end of board
  placeXY(0, Snake::border_height + 1);
}

void SnakeImpl::drawBorder()
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

void SnakeImpl::drawScore()
{
  placeXY(0, Snake::border_height+1);
  std::cout << "Current Score:" << m_score;
}

void SnakeImpl::draw()
{
  clearScreen();
  drawBorder();
  drawGameBoard();
  drawScore();
  std::cout << std::flush;
}

Snake::Direction SnakeImpl::input()
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

void SnakeImpl::logic()
{
  Snake::Direction new_dir = input();
  // Track last position
  auto tail = m_tailPtr->back();
  
  m_lastTailPos.first = tail.first;
  m_lastTailPos.second = tail.second;

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

  // Once we have moved to a new direction, we first check if we have
  // collided with tail. If not, check fruit
  if (hasCollidedWithTail()) {
    m_gameOver = true;
  } else if (hasEatenFruit()) {
    m_score++;
    growSnake(m_lastTailPos.first, m_lastTailPos.second);
    fruitSetUp(); // Get new fruit
  }
}

void SnakeImpl::moveLeft()
{
  // Move everything left
  for (auto &pair : *m_tailPtr)
  {
    if (pair.first > 1) {
      pair.first--;
    } else if (pair.first == 1) {
      pair.first = Snake::border_width - 2;
    }
  }
}

void SnakeImpl::moveRight()
{
//   m_tailLastPos.first = m_headPosition.first;

//   if (m_headPosition.first < (Snake::border_width-2)) {
//     m_headPosition.first++;
//   } else if (m_headPosition.first == (Snake::border_width-2)) {
//     m_headPosition.first = 1 ;
//   }
}

// Going up means Y coord is getting smaller
void SnakeImpl::moveUp()
{
//   m_tailLastPos.second = m_headPosition.second;

//   if (m_headPosition.second > 1) {
//     m_headPosition.second--;
//   } else if (m_headPosition.second == 1) {
//     m_headPosition.second = Snake::border_height - 2;
//   }
}

void SnakeImpl::moveDown()
{
//   m_tailLastPos.second = m_headPosition.second;

//   if (m_headPosition.second < (Snake::border_height-2)) {
//     m_headPosition.second++;
//   } else if (m_headPosition.second == (Snake::border_height-2)) {
//     m_headPosition.second = 1 ;
//   }
}

bool SnakeImpl::hasCollidedWithTail()
{
  auto head = m_tailPtr->front();
  for (auto &pair : *m_tailPtr) {
    if (head == pair) {
      continue;
    } else if (pair.first == head.first && 
	       pair.second == head.second) {
      return true;
    }
  }

  return false;
}

bool SnakeImpl::hasEatenFruit()
{
  bool out = false;
  auto head = m_tailPtr->front();
  if (head.first == m_fruitPosition.first &&
      head.second == m_fruitPosition.second) {
    out = true;

  }

  return out;
}

// =========================================================
// SNAKE CLASS METHODS
// =========================================================

Snake::Snake() : 
  m_impl(std::make_unique<SnakeImpl>())
{
  std::cout << "Snake created!\n";
}

Snake::~Snake()
{
}

void Snake::draw()
{
  m_impl->draw();
}

void Snake::logic()
{
  m_impl->logic();
}

bool Snake::isGameOver()
{
  return m_impl->isGameOver();
}

void Snake::moveLeft()
{
  m_impl->moveLeft();
}

void Snake::moveRight()
{
  m_impl->moveRight();
}

// Going up means Y coord is getting smaller
void Snake::moveUp()
{
  m_impl->moveUp();
}

void Snake::moveDown()
{
  m_impl->moveDown();
}

bool Snake::hasCollidedWithTail()
{
  return m_impl->hasCollidedWithTail();
}

bool Snake::hasEatenFruit()
{
  return m_impl->hasEatenFruit();
}
