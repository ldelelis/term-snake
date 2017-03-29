#ifndef SNAKE_HPP
#define SNAKE_HPP

class Snake {
private:
  const char segment = '#';
  unsigned int xPos, yPos, lastXPos, lastYPos;
public:
  Snake (uint_t xPos, uint_t yPos, uint_t lastXPos, uint_t lastYPos);
  moveSegmentsTick();
};

#endif
