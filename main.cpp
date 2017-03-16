#include <iostream>
#include <ncurses.h>

#include "init.hpp"
#include "snake.hpp"

void inicializarNcurses();

int main () {
  Init::inicializarNcurses();        // Arrancamos todas las funciones necesarias para iniciar el modo ncurses
  int keyPressed = 0;
  while (keyPressed != 27) {
    keyPressed = getch();
    switch (keyPressed) {
      case KEY_UP:
        std::cout << "flecha arriba\r" << std::endl;
        break;
      case KEY_DOWN:
        std::cout << "flecha abajo\r" << std::endl;
        break;
      case KEY_LEFT:
        std::cout << "flecha izquierda\r" << std::endl;
        break;
      case KEY_RIGHT:
        std::cout << "flecha derecha\r" << std::endl;
        break;
    }
    refresh();
  }
  endwin();
  return 0;
}

