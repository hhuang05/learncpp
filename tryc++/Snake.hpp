#ifndef SNAKE_H_
#define SNAKE_H_

#include <iostream>
#include <memory>

class SnakeImpl;

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

  static const int border_width = 15;
  static const int border_height = 10;

  Snake();
  ~Snake();

  void draw();
  void logic();
  bool isGameOver();

private:
  std::unique_ptr<SnakeImpl> m_impl;

  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();

  bool hasCollidedWithTail();
  bool hasEatenFruit();
};

#endif
