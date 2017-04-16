#include "snake.hpp"

void Snake::modifyHeadPos (char curMovement) {
  switch (curMovement) {
  case 'u':
    this->yPos-=1;
    break;
  case 'd':
    this->yPos+=1;
    break;
  case 'l':
    this->xPos-=1;
    break;
   case 'r':
    this->xPos+=1;
    break;
  default:
    return;
  }
}
