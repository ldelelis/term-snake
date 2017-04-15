#include "snake.hpp"

void Snake::modifyHeadPos (char curMovement) {
  switch (curMovement) {
  case 'u':
    --this->yPos;
  case 'd':
    ++this->yPos;
  case 'l':
    --this->xPos;
  case 'r':
    ++this->xPos;
  default:
    return;
  }
}
