#include "comida.hpp"

Comida::Comida() {
  randyx(this->yPos, this->xPos);
  mvprintw (this->yPos, this->xPos, '*\r');
}
