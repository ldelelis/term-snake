#include <ncurses.h>
#include <vector>

#include "init.hpp"
#include "snake.hpp"

typedef unsigned int uint_t;

int main () {
  std::vector <Snake> snakeVector;
  uint_t xRows=0, yCols=0, lastX, lastY;
  char curMovement='a', lastMovement='a';
  Init::inicializarNcurses(snakeVector);        // Arrancamos todas las funciones necesarias para iniciar el modo ncurses
  while (curMovement != 'e') {                   // Mientras no hayamos apretado ESC
    lastMovement = curMovement;
    curMovement = Init::inicializarTecla(curMovement, lastMovement);     // Obtenemos el movimiento actual
    refresh();                                    // Flusheamos todo a la pantalla
    napms(300);                                   // Pausa entre los ticks TODO: buscar una mejor alternativa si existe
  }
  endwin();                                       // Finalizamos el modo ncurses para evitar bugs con la terminal
  return 0;
}

