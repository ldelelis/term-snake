#include "snake.hpp"

Snake::Snake(uint_t lastX, uint_t lastY) {
  this.xPos = 600;
  this.yPos = 600;
  this.moveLastSegment(lastX, lastY);
}

void printSegmentsTick (std::string snakeVector, int it) {
  mvprintw(snakeVector.at(it).yPos, snakeVector.at(it).xPos, snakeVector.segment);
  mvprintw(snakeVector.at(it).lastXpos, snakeVector.at(it).lastYpos, " \r");
}

void moveSegmentsTick (std::vector snakeVector) {
  int it=0;
  for (it;it<=snakeVector.size(); it++) {
    snakeVector.at(it).lastXPos = vibora.at(it).xPos;
    snakeVector.at(it).lastYPos = vibora.at(it).yPos;
    if (it > 0) {
      snakeVector.at(it).xPos = snakeVector.at(it-1).lastXPos;
      snakeVector.at(it).yPos = snakeVector.at(it-1).lastYPos;
    } else {
      this.moveHead(curMovement);
    }
    printSegmentsTick (snakeVector, it);
  }
}

void moveHead (char curMovement) {
  switch (curMovement) {
    case 'u':
      this.decrementY();
      break;
    case 'd':
      this.incrementY();
      break;
    case 'l':
      this.decrementX();
      break;
    case 'r':
      this.incrementX();
      break;
  }
}
