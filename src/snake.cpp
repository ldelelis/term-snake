#include "snake.hpp"

void Snake::modifyHeadPos (char curMovement) {
  switch (curMovement) {
  case 'u':
    this->yPos-=1;
    std::cout << this->yPos << std::endl;
  case 'd':
    this->yPos+=1;
    std::cout << this->yPos << std::endl;
  case 'l':
    this->xPos-=1;
    std::cout << this->xPos << std::endl;
   case 'r':
    this->xPos+=1;
    std::cout << this->xPos << std::endl;
  default:
    return;
  }
}
