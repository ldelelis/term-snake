#include <ncurses.h>
#include <iostream>
#include <vector>

#include "init.hpp"

namespace Init {
  void inicializarAxis(std::vector <Snake> &snakeVector) {
    uint_t xRows, yCols;
    snakeVector.emplace_back(600, 600);
    getmaxyx(stdscr, yCols, xRows); // Devuelve el maximo de columnas y filas
    xRows /= 2;                     // Centramos dicho máximo
    yCols /= 2;
    snakeVector.at(0).setX(xRows);        // Y lo asignamos como valor inicial post constructor
    snakeVector.at(0).setY(yCols);
  }

  void inicializarNcurses(std::vector <Snake> &snakeVector) {
    initscr();                      // Arranca el modo ncurses
    cbreak();                       // Habilita el envío de señales
    noecho();                       // Deshabilita el print del caracter tomado
    keypad(stdscr, TRUE);           // Nos permite usar las flechas (vital para el juego)
    nodelay(stdscr, TRUE);          // Tomamos ingresos sin esperarlos
    curs_set(0);                    // Deshabilitamos el renderizado del cursor
    Init::inicializarAxis(snakeVector); // Pasamos nuestra víbora para inicializar sus valores X,Y
  }

  char inicializarTecla(char curMovement, char lastMovement) {
    int keyPressed = getch();       // Esperamos el ingreso de una tecla
    switch (keyPressed) {           // Y trabajamos sobre tal
    case KEY_UP:                    // Arriba
      if (lastMovement == 'd') {    // Si colisiona con si misma
        return curMovement;         // La dirección no cambia.
      }
      return 'u';                   // Caso contrario, cambiamos de dirección.
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
    case 27:                         // 27 es el intcode de Escape.
      return 'e';
    default:                         // Si no obtiene ningun ingreso...
      return curMovement;            // Sigue yendo en la misma dirección.
    }
  }
}
