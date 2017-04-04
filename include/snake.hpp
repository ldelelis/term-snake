#ifndef SNAKE_HPP
#define SNAKE_HPP

class Snake {
private:
  const char segment = '#';
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

previo al metodo se mueve manualmente el primer segmento
metodochotoparamoverse (vector serpiente, lastx, lasty) {
  
}
