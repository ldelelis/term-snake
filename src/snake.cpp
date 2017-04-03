#include <ncurses.h>

#include "snake.hpp"

Snake::Snake(uint_t lastX, uint_t lastY) {
  this.xPos = 600;
  this.yPos = 600;
  this.moveLastSegment(lastX, lastY);
}

uint_t getX() {
  return this.xPos;
}

uint_t getY() {
  return this.yPos;
}

void incrementX() {
  ++this.xPos;
}

void incrementY() {
  ++this.yPos;
}

void decrementX() {
  --this.xPos;
}

void decrementY() {
  --this.yPos;
}

void moveSegmentsTick (uint_t tempLastX, uint_t tempLastY) {
  mvprintw(this.yPos, this.xPos, this.segment);
  mvprintw(this.lastXpos, this.lastYpos, " ");
}

void moveLastSegment (uint_t lastX, uint_t lastY) {
  this.x = lastX;
  this.y = lastY;
}
