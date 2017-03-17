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
        curMovement = 'u';
        if (xRows != 0 && yCols != 0) {
            --yCols;
            mvprintw(yCols, xRows, "flecha arriba\r");
        } else {
          erase();
          Init::inicializarAxis(xRows, yCols);
          curMovement = 'a';
        }
    }
    else if (keyPressed == KEY_DOWN || curMovement == 'd') {
        curMovement = 'd';
        if (xRows != 0 && yCols != 0) {
            ++yCols;
            mvprintw(yCols, xRows, "flecha abajo\r");
        } else {
          erase();
          Init::inicializarAxis(xRows, yCols);
          curMovement = 'a';
        }
    }
    else if (keyPressed == KEY_LEFT || curMovement == 'l') {
        curMovement = 'l';
        if (xRows != 0 && yCols != 0) {
            --xRows;
            mvprintw(yCols, xRows, "flecha izquierda\r");
        } else {
          erase();
          Init::inicializarAxis(xRows, yCols);
          curMovement = 'a';
        }
    }
    else if (keyPressed == KEY_RIGHT || curMovement == 'r') {
        curMovement = 'r';
        if (xRows != 0 && yCols != 0) {
            ++xRows;
            mvprintw(yCols, xRows, "flecha derecha\r");
        } else {
          erase();
          Init::inicializarAxis(xRows, yCols);
          curMovement = 'a';
        }
    }
    refresh();
  }
  endwin();
  return 0;
}

