#include <iostream>
#include <ncurses.h>

#include "init.hpp"
#include "snake.hpp"

int main () {
  int xRows=0, yCols=0, lastX, lastY, keyPressed=0;
  char curMovement='a', lastMovement='a';
  Init::inicializarNcurses(xRows, yCols);        // Arrancamos todas las funciones necesarias para iniciar el modo ncurses
  while (curMovement != 'e') {
    lastMovement = curMovement;
    curMovement = Init::inicializarTecla(curMovement, lastMovement);
    keyPressed = getch();
    if (curMovement == 'u') {
      if (xRows != 0 && yCols != 0) {
        lastX = xRows;
        lastY = yCols;
        --yCols;
        mvprintw(yCols, xRows, "u\r");
        mvprintw(lastY, lastX, " \r");
      } else {
        erase();
        Init::inicializarAxis(xRows, yCols);
        curMovement = 'a';
      }
    }
    else if (curMovement == 'd') {
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
    else if (curMovement == 'l') {
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
    else if (curMovement == 'r') {
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
    refresh();
    napms(300);
  }
  endwin();
  return 0;
}

