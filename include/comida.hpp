#ifndef COMIDA_HPP
#define COMIDA_HPP

typedef unsigned int uint_t;

class Comida {
private:
  uint_t xPos, yPos;
public:
  Comida();
  uint_t getX() { return this->xPos; }
  uint_t getY() { return this->yPos; }
};

#endif
