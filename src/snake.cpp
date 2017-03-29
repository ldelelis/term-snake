#include <ncurses.h>

#include "snake.hpp"

Snake::Snake() {
  this.xPos = this.lastXPos;
  this.yPos = this.lastYPos;
}

uint_t getX() {
  return this.xPos;
}

uint_t getY() {
  return this.yPos;
}

void moveSegmentsTick (uint_t tempLastX, uint_t tempLastY) {
  mvprintw(this.yPos, this.xPos, this.segment);
  mvprintw(this.lastXpos, this.lastYpos, " ");
}
