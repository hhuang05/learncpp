#ifndef SNAKE_H_
#define SNAKE_H_

#include <iostream>
#include <utility>


class Snake
{

public:
  enum Direction
  {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STOPPED
  };

private:
  bool m_gameOver;
  int m_score;
  Snake::Direction m_direction;
  std::pair<int, int> m_headPosition;
  std::pair<int, int> m_fruitPosition;

  void snakeSetUp();
  void fruitSetUp();
  void drawGameBoard();
  void drawBorder();

public:
  static const int border_width = 15;
  static const int border_height = 10;

  Snake() : 
    m_gameOver(false), 
    m_score(0),
    m_direction(Direction::STOPPED),
    m_headPosition(std::make_pair(0,0)),
    m_fruitPosition(std::make_pair(0,0))
  {
    snakeSetUp();
    fruitSetUp();
    std::cout << "Snake created!\n";
  };

  ~Snake()
  {
    std::cout << "Snake destroyed!\n";
  };

  void draw();
  Snake::Direction input();
  void logic();
  bool isGameOver() { return m_gameOver; }; 
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();


};

#endif
