#include "Utilities.hpp"

#include <mutex>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

char getch()
{
  char buf=0;
  struct termios old={
    0,   // c_iflag
    0,   // c_oflag
    0,   // c_cflag
    0,   // c_lflag
    {0}, // c_cc
    0,   // c_ispeed
    0    // c_ospeed
  };
  fflush(stdout);

  if(tcgetattr(0, &old)<0)
    perror("tcsetattr()");

  old.c_lflag&=~ICANON;
  old.c_lflag&=~ECHO;
  old.c_cc[VMIN]=1;
  old.c_cc[VTIME]=0;
  if(tcsetattr(0, TCSANOW, &old)<0)
    perror("tcsetattr ICANON");

  if(read(0,&buf,1)<0)
    perror("read()");

  old.c_lflag|=ICANON;
  old.c_lflag|=ECHO;
  if(tcsetattr(0, TCSADRAIN, &old)<0)
    perror ("tcsetattr ~ICANON");

  // Uncomment this to echo the char
  //printf("%c\n",buf);
  return buf;
}

std::once_flag seedFlag;
void randomNumberSeedImpl() {
  std::call_once(seedFlag, []() {
      // Seed the random-number generator with the current time so that
      // the numbers will be different every time we run.
      srand(time(0));
    });
}

int randomNumberImpl() {
  return rand();
}

char getCharImpl() {
  return getch();
}

void clearImpl() {
  std::cout << std::flush;
  std::system("clear");
  //std::cout << "\033[2J";
}

void placeXYImpl(const int column, const int line) {
  // note: 1,1 is the top left corner on Linux and Mac
  int lColumn = column + 1;
  int lLine   = line + 1;
  std::cout << "\033[" << lLine << ";" << lColumn << "H";
}


void randomNumberSeed() {
  randomNumberSeedImpl();
}

int randomNumber() {
  return randomNumberImpl();
}

void clearScreen()
{
  clearImpl();
}

char getChar()
{
  return getCharImpl();
}

void placeXY(const int column, const int line)
{
  // 0, 0 is the top left corner
  placeXYImpl(column, line);
}
