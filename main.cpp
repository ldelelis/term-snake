#include <iostream>
#include <ncurses.h>

#include "init.hpp"
#include "snake.hpp"

void inicializarNcurses();

int main () {
  int xRows=0, yCols=0;
  char curMovement;
  Init::inicializarNcurses(xRows, yCols);        // Arrancamos todas las funciones necesarias para iniciar el modo ncurses
  int keyPressed = 0;
  while (keyPressed != 27) {
    keyPressed = getch();
    if (keyPressed == KEY_UP || curMovement == 'u') {
        --yCols;
        curMovement = 'u';
        mvprintw(yCols, xRows, "flecha arriba\r");
    }
    else if (keyPressed == KEY_DOWN || curMovement == 'd') {
        ++yCols;
        curMovement = 'd';
        mvprintw(yCols, xRows, "flecha abajo\r");
    }
    else if (keyPressed == KEY_LEFT || curMovement == 'l') {
        --xRows;
        curMovement = 'l';
        mvprintw(yCols, xRows, "flecha izquierda\r");
    }
    else if (keyPressed == KEY_RIGHT || curMovement == 'r') {
        ++xRows;
        curMovement = 'r';
        mvprintw(yCols, xRows, "flecha derecha\r");
    }
    refresh();
  }
  endwin();
  return 0;
}

