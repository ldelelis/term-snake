#include "movement.hpp"

namespace Movement {
  void printSegmentsTick (std::vector <Snake> &snakeVector, int it, char curMovement) {
    mvprintw(snakeVector.at(it).getY(), snakeVector.at(it).getX(), "#\r"); //Imprimimos el segmento en la posición avanzada...
    if (curMovement != 'a') {
      mvprintw(snakeVector.at(it).getLastY(), snakeVector.at(it).getLastX(), " \r"); // Y borramos el leftover en la posición anterior.
    }
  }

  void moveSegmentsTick (std::vector <Snake> &snakeVector, char &curMovement, Comida *&pedazo) {
    uint_t it=0, lastXPos, lastYPos, xPos, yPos;
    for (it=0; it<snakeVector.size(); it++) {    // Arrancamos la iteración para cada segmento de la vibora.
      xPos=snakeVector.at(it).getX();
      yPos=snakeVector.at(it).getY();
      snakeVector.at(it).setLastX(xPos);  // Asignamos lo que seria la posición X anterior
      snakeVector.at(it).setLastY(yPos);  // Idem a la posición Y
      if (it > 0) {  // Para todos los segmentos luego del primero (head)...
        lastXPos = snakeVector.at(it-1).getLastX();
        lastYPos = snakeVector.at(it-1).getLastY();
        snakeVector.at(it).setX(lastXPos);  // Le pasamos la posición X anterior del de adelante a la actual.
        snakeVector.at(it).setY(lastYPos);  // Idem a la pos Y
      } else {  // Para el primer segmento (head)...
        snakeVector.at(it).modifyHeadPos(curMovement, snakeVector, pedazo);  // Leemos curMovement y asignamos la dirección
      }
      Movement::printSegmentsTick (snakeVector, it, curMovement); // Imprimimos cada segmento al final de cada iteración, luego de mover las posiciones correspondientes.
    }
  }

  void growSize(std::vector <Snake> &snakeVector) {
    snakeVector.emplace_back(600,600,600,600);
  }

  bool checkCollision(std::vector <Snake> &snakeVector) {
    uint_t it;
    for (it=3;it<snakeVector.size();it++) {
      if (snakeVector.at(0).getY() == snakeVector.at(it).getY() && snakeVector.at(0).getX() == snakeVector.at(it).getX()) {
        return true;
      }
    }
    return false;
  }
}
