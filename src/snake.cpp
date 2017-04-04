#include <ncurses.h>

#include "snake.hpp"

Snake::Snake(uint_t lastX, uint_t lastY) {
  this.xPos = 600;
  this.yPos = 600;
  this.moveLastSegment(lastX, lastY);
}

void moveSegmentsTick (uint_t tempLastX, uint_t tempLastY) {
  mvprintw(this.yPos, this.xPos, this.segment);
  mvprintw(this.lastXpos, this.lastYpos, " ");
}

void moveLastSegment (uint_t lastX, uint_t lastY) {
  this.x = lastX;
  this.y = lastY;
}
