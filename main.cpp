#include <iostream>
#include <ncurses.h>

#include "init.hpp"
#include "snake.hpp"

void inicializarNcurses();

int main () {
  int xRows=0, yCols=0;
  Init::inicializarNcurses(xRows, yCols);        // Arrancamos todas las funciones necesarias para iniciar el modo ncurses
  int keyPressed = 0;
  while (keyPressed != 27) {
    keyPressed = getch();
    switch (keyPressed) {
      case KEY_UP:
        --yCols;
        mvprintw(yCols, xRows, "flecha arriba\r");
        break;
      case KEY_DOWN:
        ++yCols;
        mvprintw(yCols, xRows, "flecha abajo\r");
        break;
      case KEY_LEFT:
        --xRows;
        mvprintw(yCols, xRows, "flecha izquierda\r");
        break;
      case KEY_RIGHT:
        ++xRows;
        mvprintw(yCols, xRows, "flecha derecha\r");
        break;
    }
    refresh();
  }
  endwin();
  return 0;
}

