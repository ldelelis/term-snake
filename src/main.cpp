#include <ncurses.h>
#include <vector>

#include "init.hpp"
#include "snake.hpp"
#include "movement.hpp"
#include "comida.hpp"

typedef unsigned int uint_t;

int main () {
  std::vector <Snake> snakeVector;
  char curMovement, lastMovement;
  Comida *pedazo=nullptr;
  Init::inicializarNcurses(snakeVector, curMovement);          // Arrancamos todas las funciones necesarias para iniciar el modo ncurses
  Init::inicializarFoodPointer(pedazo);
  while (curMovement != 'e') {                    // Mientras no hayamos apretado ESC
    lastMovement = curMovement;
    curMovement = Init::inicializarTecla(curMovement, lastMovement);     // Obtenemos el movimiento actual
    Movement::moveSegmentsTick(snakeVector, curMovement, pedazo);
    refresh();                                    // Flusheamos todo a la pantalla
    napms(100);                                   // Pausa entre los ticks TODO: buscar una mejor alternativa si existe
  }
  endwin();                                       // Finalizamos el modo ncurses para evitar bugs con la terminal
  delete pedazo;
  return 0;
}
