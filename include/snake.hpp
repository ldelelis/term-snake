#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <string>

class Snake {
private:
  std::string segment = '#\r';
  unsigned int xPos, yPos, lastXPos, lastYPos;
public:
  Snake (uint_t xPos, uint_t yPos) : xPos(600), yPos(600);
  void moveSegmentsTick();
  void moveLastSegment(uint_t lastX, uint_t lastY);
  uint_t getX() { return this.xPos; }
  uint_t getY() { return this.yPos; }
  void incrementX() { ++this.xPos; }
  void incrementY() { ++this.yPos; }
  void decrementX() { --this.xPos; }
  void decrementY() { --this.yPos; }
};

#endif

/*
previo al metodo se mueve manualmente el primer segmento
metodochotoparamoverse (vector serpiente, lastx, lasty) {
  int it=1;
  for (it; it<=vivbora.size();it++) {
    vibora.at(it).lastXPos = vibora.at(it).xPos;
    vibora.at(it).lastYPos = vibora.at(it).YPos;
    vibora.at(it).xPos = vibora.at(it-1).lastXPos;
    vibora.at(it).yPos = vibora.at(it-1).lastYPos;
    funcionchoteraparaimprimir(xPos, yPos, lastXPos, lastYPos);
  }
}

funcionchoteraparaimprimir (xpos ypos lastxpos lastypos) {
  mvprintw (this.segment+"\r", this.ypos, this.xpos);
  mvprintw (" \r", this.lastypos, this.lastxpos);
}
*/
