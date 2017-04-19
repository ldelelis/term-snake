#include <ncurses.h>
#include <iostream>
#include <vector>

#include "init.hpp"

namespace Init {
  void inicializarAxis(std::vector <Snake> &snakeVector, char &curMovement) {
    uint_t xRows, yCols;
    curMovement = 'a';
    clear();
    snakeVector.clear();
    snakeVector.emplace_back(600, 600, 600, 600);
    getmaxyx(stdscr, yCols, xRows); // Devuelve el maximo de columnas y filas
    xRows /= 2;                     // Centramos dicho máximo
    yCols /= 2;
    snakeVector.at(0).setX(xRows);  // Y lo asignamos como valor inicial post constructor
    snakeVector.at(0).setY(yCols);
    mvprintw(snakeVector.at(0).getY(), snakeVector.at(0).getX(), "#\r");
  }

  void inicializarNcurses(std::vector <Snake> &snakeVector, char &curMovement) {
    initscr();                      // Arranca el modo ncurses
    cbreak();                       // Habilita el envío de señales
    noecho();                       // Deshabilita el print del caracter tomado
    keypad(stdscr, TRUE);           // Nos permite usar las flechas (vital para el juego)
    nodelay(stdscr, TRUE);          // Tomamos ingresos sin esperarlos
    curs_set(0);                    // Deshabilitamos el renderizado del cursor
    Init::inicializarAxis(snakeVector, curMovement); // Pasamos nuestra víbora para inicializar sus valores X,Y
  }

  char inicializarTecla(char curMovement, char lastMovement) {
    int keyPressed = getch();       // Esperamos el ingreso de una tecla
    switch (keyPressed) {           // Y trabajamos sobre tal
    case KEY_UP:                    // Arriba
      if (lastMovement == 'd') {    // Si colisiona con si misma
        return lastMovement;         // La dirección no cambia.
      }
      return 'u';                   // Caso contrario, cambiamos de dirección.
    case KEY_DOWN:
      if (lastMovement == 'u') {
        return lastMovement;
      }
      return 'd';
    case KEY_LEFT:
      if (lastMovement == 'r') {
        return lastMovement;
      }
      return 'l';
    case KEY_RIGHT:
      if (lastMovement == 'l') {
        return lastMovement;
      }
      return 'r';
    case 27: case 'q':               // 27 es el intcode de Escape.
      return 'e';
    default:                         // Si no obtiene ningun ingreso...
      return curMovement;            // Sigue yendo en la misma dirección.
    }
  }

  void inicializarFoodPointer(Comida *&pedazo) {
    if (pedazo) {
      delete pedazo;
    }
    pedazo = new Comida();
  }
}
