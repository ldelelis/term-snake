#include "snake.hpp"
#include "init.hpp"
#include "movement.hpp"

void Snake::modifyHeadPos (char &curMovement, std::vector <Snake> &snakeVector, Comida *&pedazo) {
  uint_t maxY, maxX;
  getmaxyx (stdscr, maxY, maxX);
  switch (curMovement) {
  case 'u':
    this->yPos-=1;
    if (this->yPos <= 0) {
      Init::inicializarAxis(snakeVector, curMovement);
      Init::inicializarFoodPointer(pedazo);
    }
    break;
  case 'd':
    this->yPos+=1;
    if (this->yPos >= maxY) {
      Init::inicializarAxis(snakeVector, curMovement);
      Init::inicializarFoodPointer(pedazo);
    }
    break;
  case 'l':
    this->xPos-=1;
    if (this->xPos <= 0) {
      Init::inicializarAxis(snakeVector, curMovement);
      Init::inicializarFoodPointer(pedazo);
    }
    break;
   case 'r':
    this->xPos+=1;
    if (this->xPos >= maxX) {
      Init::inicializarAxis(snakeVector, curMovement);
      Init::inicializarFoodPointer(pedazo);
    }
    break;
  default:
    break;
  }
  if (Movement::checkCollision(snakeVector)) {
      Init::inicializarAxis(snakeVector, curMovement);
      Init::inicializarFoodPointer(pedazo);
    }
  if (this->xPos == pedazo->getX() && this->yPos == pedazo->getY()) {
    Movement::growSize(snakeVector);
    Init::inicializarFoodPointer(pedazo);
  }
}
