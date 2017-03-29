#ifndef SNAKE_HPP
#define SNAKE_HPP

class Snake {
private:
  const char segment = '#';
  unsigned int xPos, yPos, lastXPos, lastYPos;
public:
  Snake (uint_t xPos, uint_t yPos, uint_t lastXPos, uint_t lastYPos);
  void moveSegmentsTick();
  uint_t getX();
  uint_t getY();
  void incrementX();
  void incrementY();
  void decrementX();
  void decrementY();
};

#endif
