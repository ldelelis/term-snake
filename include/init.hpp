#ifndef INIT_HPP
#define INIT_HPP

#include <ncurses.h>
#include <iostream>


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

  char inicializarTecla(char curMovement) {
    int keyPressed = getch();
    switch (keyPressed) {
      case KEY_UP:
        return 'u';
      case KEY_DOWN:
        return 'd';
      case KEY_LEFT:
        return 'l';
      case KEY_RIGHT:
        return 'r';
      case 27:
        return 'e';
      default:
        return curMovement;
    }
  }
}

#endif
