#ifndef INIT_HPP
#define INIT_HPP

#include <ncurses.h>


namespace Init {
  void inicializarNcurses() {
    initscr();               // Arranca el modo ncurses
    cbreak();                // Habilita el envío de señales
    noecho();                // Deshabilita el print del caracter tomado
    keypad(stdscr, TRUE);    // Nos permite usar las flechas (vital para el juego)
    nodelay(stdscr, TRUE);   // Tomamos ingresos sin esperarlos
  }
}

#endif
