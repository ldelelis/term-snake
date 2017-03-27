#include <ncurses.h>

#include "init.hpp"
#include "snake.hpp"

int main () {
  int xRows=0, yCols=0, lastX, lastY;
  char curMovement='a', lastMovement='a';
  Init::inicializarNcurses(xRows, yCols);        // Arrancamos todas las funciones necesarias para iniciar el modo ncurses
  while (curMovement != 'e') {                   // Mientras no hayamos apretado ESC
    lastMovement = curMovement;
    curMovement = Init::inicializarTecla(curMovement, lastMovement);     // Obtenemos el movimiento actual
    if (curMovement == 'u') {                    // Arriba
      if (xRows != 0 && yCols != 0) {            // Si no llegamos al borde...
        lastX = xRows;                           // Obtenemos las posiciones anteriores...
        lastY = yCols;
        --yCols;                                 // ... realizamos el movimiento necesario...
        mvprintw(yCols, xRows, "u\r");           // ... imprimimos el segmento de la serpiente...
        mvprintw(lastY, lastX, " \r");           // ... y borramos el anterior
      } else {                                   // Caso Contrario:
        erase();                                 // Vaciamos completamente la pantalla...
        Init::inicializarAxis(xRows, yCols);     // ... reinicializamos las posiciones en el centro...
        curMovement = 'a';                       // Y dejamos el juego en hold hasta obtener un input de dirección.
      }
    }
    else if (curMovement == 'd') {               // Abajo
      if (xRows != COLS && yCols != LINES) {
        lastX = xRows;
        lastY = yCols;
        ++yCols;
        mvprintw(yCols, xRows, "d\r");
        mvprintw(lastY, lastX, " \r");
      } else {
        erase();
        Init::inicializarAxis(xRows, yCols);
        curMovement = 'a';
      }
    }
    else if (curMovement == 'l') {               // Izquierda
      if (xRows != 0 && yCols != 0) {
        lastX = xRows;
        lastY = yCols;
        --xRows;
        mvprintw(yCols, xRows, "l\r");
        mvprintw(lastY, lastX, " \r");
      } else {
        erase();
        Init::inicializarAxis(xRows, yCols);
        curMovement = 'a';
      }
    }
    else if (curMovement == 'r') {               // Derecha
      if (xRows != COLS  && yCols != LINES) {
        lastX = xRows;
        lastY = yCols;
        ++xRows;
        mvprintw(yCols, xRows, "r\r");
        mvprintw(lastY, lastX, " \r");
      } else {
        erase();
        Init::inicializarAxis(xRows, yCols);
        curMovement = 'a';
      }
    }
    refresh();                                    // Flusheamos todo a la pantalla
    napms(300);                                   // Pausa entre los ticks TODO: buscar una mejor alternativa si existe
  }
  endwin();                                       // Finalizamos el modo ncurses para evitar bugs con la terminal
  return 0;
}

