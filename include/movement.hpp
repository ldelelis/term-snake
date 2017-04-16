#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <vector>

#include "movement.hpp"
#include "snake.hpp"

namespace Movement {
  void printSegmentsTick(std::vector <Snake> &snakeVector, int it);
  void moveSegmentsTick(std::vector <Snake> &snakeVector, char &curMovement);
}

#endif
