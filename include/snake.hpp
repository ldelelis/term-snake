#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>

#include "comida.hpp"

typedef unsigned int uint_t;

class Snake {
private:
  uint_t xPos, yPos, lastXPos, lastYPos;
public:
  Snake (uint_t xPos, uint_t yPos, uint_t lastXPos, uint_t lastYPos) : xPos(600), yPos(600), lastXPos(600), lastYPos(600) {}
  uint_t getX() { return this->xPos; }
  uint_t getY() { return this->yPos; }
  uint_t getLastX() { return this->lastXPos; }
  uint_t getLastY() { return this->lastYPos; }
  void setX(uint_t x) { xPos = x; }
  void setY(uint_t y) { yPos = y; }
  void setLastX(uint_t x) { lastXPos = x; }
  void setLastY(uint_t y) { lastYPos = y; }
  void modifyHeadPos (char &curMovement, std::vector <Snake> &snakeVector, Comida *&pedazo);
};

#endif
