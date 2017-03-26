#include <ncurses.h>
#include <iostream>

#include "init.hpp"

namespace Init {
  void inicializarAxis(int &xRows, int &yCols) {
    getmaxyx(stdscr, yCols, xRows); // Devuelve el maximo de columnas y filas
    xRows /= 2;
    yCols /= 2;
  }

  void inicializarNcurses(int &xRows, int &yCols) {
    initscr();                      // Arranca el modo ncurses
    cbreak();                       // Habilita el envío de señales
    noecho();                       // Deshabilita el print del caracter tomado
    keypad(stdscr, TRUE);           // Nos permite usar las flechas (vital para el juego)
    nodelay(stdscr, TRUE);          // Tomamos ingresos sin esperarlos
    Init::inicializarAxis(xRows, yCols);
  }

  char inicializarTecla(char curMovement, char lastMovement) {
    int keyPressed = getch();
    switch (keyPressed) {
    case KEY_UP:
      if (lastMovement == 'd') {
        return curMovement;
      }
      return 'u';
    case KEY_DOWN:
      if (lastMovement == 'u') {
        return curMovement;
      }
      return 'd';
    case KEY_LEFT:
      if (lastMovement == 'r') {
        return curMovement;
      }
      return 'l';
    case KEY_RIGHT:
      if (lastMovement == 'l') {
        return curMovement;
      }
      return 'r';
    case 27:
      return 'e';
    default:
      return curMovement;
    }
  }
}
