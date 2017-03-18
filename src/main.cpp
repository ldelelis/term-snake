#include <iostream>
#include <ncurses.h>

#include "init.hpp"
#include "snake.hpp"

int main () {
  int xRows=0, yCols=0, keyPressed=0;
  char curMovement;
  Init::inicializarNcurses(xRows, yCols);        // Arrancamos todas las funciones necesarias para iniciar el modo ncurses
  while ((int)curMovement != 27) {
    curMovement = Init::inicializarTecla(curMovement);
      keyPressed = getch();
      if (curMovement == 'u') {
          if (xRows != 0 && yCols != 0) {
              --yCols;
              mvprintw(yCols, xRows, "u\r");
          } else {
            erase();
            Init::inicializarAxis(xRows, yCols);
            curMovement = 'a';
          }
      }
      else if (curMovement == 'd') {
          if (xRows != COLS && yCols != LINES) {
              ++yCols;
              mvprintw(yCols, xRows, "d\r");
          } else {
            erase();
            Init::inicializarAxis(xRows, yCols);
            curMovement = 'a';
          }
      }
      else if (curMovement == 'l') {
          if (xRows != 0 && yCols != 0) {
              --xRows;
              mvprintw(yCols, xRows, "l\r");
          } else {
            erase();
            Init::inicializarAxis(xRows, yCols);
            curMovement = 'a';
          }
      }
      else if (curMovement == 'r') {
          if (xRows != COLS  && yCols != LINES) {
              ++xRows;
              mvprintw(yCols, xRows, "r\r");
          } else {
            erase();
            Init::inicializarAxis(xRows, yCols);
            curMovement = 'a';
          }
      }
    refresh();
    napms(300);
  }
  endwin();
  return 0;
}

