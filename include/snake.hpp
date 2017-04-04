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
  uint_t getX();
  uint_t getY();
  void incrementX();
  void incrementY();
  void decrementX();
  void decrementY();
};

#endif
