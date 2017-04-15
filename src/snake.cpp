#include "snake.hpp"

void Snake::modifyHeadPos (char curMovement) {
  switch (curMovement) {
  case 'u':
    this->yPos-=1;
  case 'd':
    this->yPos+=1;
  case 'l':
    this->xPos-=1;
  case 'r':
    this->xPos+=1;
  default:
    return;
  }
}
