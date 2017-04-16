#include "snake.hpp"
#include "init.hpp"

void Snake::modifyHeadPos (char &curMovement, std::vector <Snake> &snakeVector, uint_t it) {
  uint_t maxY, maxX;
  getmaxyx(stdscr, maxY, maxX);
  switch (curMovement) {
  case 'u':
    this->yPos-=1;
    if (this->yPos <= 0) {
      Init::inicializarAxis(snakeVector, curMovement);
    }
    break;
  case 'd':
    this->yPos+=1;
    if (this->yPos >= maxY) {
      Init::inicializarAxis(snakeVector, curMovement);
    }
    break;
  case 'l':
    this->xPos-=1;
    if (this->xPos <= 0) {
      Init::inicializarAxis(snakeVector, curMovement);
    }
    break;
   case 'r':
    this->xPos+=1;
    if (this->xPos >= maxX) {
      Init::inicializarAxis(snakeVector, curMovement);
    }
    break;
  default:
    break;
  }
}
