#ifndef INIT_HPP
#define INIT_HPP

#include <ncurses.h>
#include <iostream>

#include "comida.hpp"
#include "snake.hpp"

namespace Init {
  void inicializarAxis(std::vector <Snake> &snakeVector, char &curMovement);
  void inicializarNcurses(std::vector <Snake> &snakeVector, char &curMovement);
  char inicializarTecla(char curMovement, char lastMovement);
  void inicializarFoodPointer(Comida *&pedazo);
}

#endif
