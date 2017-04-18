//Definimos un macro para seguir el estilo de ncurses
#define randyx(y,x) {                           \
    uint_t maxY, maxX;                          \
    getmaxyx(stdscr, maxY, maxX);               \
    y=rand() % maxY;                            \
    x=rand() % maxX;                            \
  }

#include <ncurses.h>
#include <stdlib.h>
#include <iostream>

#include "comida.hpp"

Comida::Comida() {
  randyx(this->yPos, this->xPos);
  mvprintw (this->yPos, this->xPos, "*\r");
}
