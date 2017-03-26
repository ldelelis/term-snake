#ifndef INIT_HPP
#define INIT_HPP

#include <ncurses.h>
#include <iostream>


namespace Init {
  void inicializarAxis(int &xRows, int &yCols);
  void inicializarNcurses(int &xRows, int &yCols);
  char inicializarTecla(char curMovement, char lastMovement);
}

#endif
