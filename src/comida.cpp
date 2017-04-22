//Definimos un macro para seguir el estilo de ncurses
#define randyx(y,x) {                         \
  srand (time(NULL));                         \
  uint_t maxY, maxX;                          \
  getmaxyx(stdscr, maxY, maxX);               \
  y=rand() % (maxY-2) +1;                     \
  x=rand() % (maxX-2) +1;                     \
  }

#include <ncurses.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "comida.hpp"

Comida::Comida() {
  randyx(this->yPos, this->xPos);
  mvprintw (this->yPos, this->xPos, "+\r");
}
