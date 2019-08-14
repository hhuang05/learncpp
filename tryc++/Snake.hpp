#ifndef SNAKE_H_
#define SNAKE_H_

#include <iostream>
#include <utility>


class Snake
{

private:
  bool m_gameOver;
  int m_score;
  std::pair<int, int> m_headPosition;
  std::pair<int, int> m_fruitPosition;

  void drawGameBoard();
  void drawBorder();

public:
  static const int border_width = 15;
  static const int border_height = 10;

  Snake() : 
    m_gameOver(false), 
    m_score(0),
    m_headPosition(std::make_pair(0,0)),
    m_fruitPosition(std::make_pair(0,0))
  {
    std::cout << "Snake created!\n";
  };

  ~Snake()
  {
    std::cout << "Snake destroyed!\n";
  };

  // Snake related functions
  void fruitSetUp();

  // Fruit related functions
  void snakeSetUp();

  void draw();
  void input();
  void logic();
  bool isGameOver() { return m_gameOver; }; 
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();


};

#endif
