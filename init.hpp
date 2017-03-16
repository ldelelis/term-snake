#ifndef INIT_HPP
#define INIT_HPP

#include <ncurses.h>


namespace Init {
  void inicializarNcurses(int &xRows, int &yCols) {
    initscr();                      // Arranca el modo ncurses
    cbreak();                       // Habilita el envío de señales
    noecho();                       // Deshabilita el print del caracter tomado
    keypad(stdscr, TRUE);           // Nos permite usar las flechas (vital para el juego)
    nodelay(stdscr, TRUE);          // Tomamos ingresos sin esperarlos
    getmaxyx(stdscr, xRows, yCols); // Devuelve el maximo de columnas y filas
  }
}

#endif
