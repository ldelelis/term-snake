#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <ncurses.h>
#include <string>
#include <vector>

class Snake {
private:
  std::string segment = '#\r';
  unsigned int xPos, yPos, lastXPos, lastYPos;
public:
  Snake (uint_t xPos, uint_t yPos) : xPos(600), yPos(600);
  void printSegmentsTick();
  uint_t getX() { return this.xPos; }
  uint_t getY() { return this.yPos; }
  void setX(uint_t x) { xPos = x; }
  void setY(uint_t y) { yPos = y; }
  void incrementX() { ++this.xPos; }
  void incrementY() { ++this.yPos; }
  void decrementX() { --this.xPos; }
  void decrementY() { --this.yPos; }
  void moveHead (char curMovement);
};

#endif
