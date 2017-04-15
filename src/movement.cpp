#include "movement.hpp"
#include "snake.hpp"

namespace Movement {
  void printSegmentsTick (std::vector <Snake> &snakeVector, int it) {
    mvprintw(snakeVector.at(it).getY(), snakeVector.at(it).getX(), "#\r"); //Imprimimos el segmento en la posición avanzada...
    mvprintw(snakeVector.at(it).getLastX(), snakeVector.at(it).getLastY(), " \r"); // Y borramos el leftover en la posición anterior.
  }

  void moveSegmentsTick (std::vector <Snake> &snakeVector, char curMovement) {
    uint_t it=0, lastXPos=snakeVector.at(it).getLastX(),
      lastYPos=snakeVector.at(it).getLastY(),    // Inicializamos el iterador en el indice 0.
      xPos=snakeVector.at(it).getX(),
      yPos=snakeVector.at(it).getY();
    for (it=0; it<snakeVector.size(); it++) {    // Arrancamos la iteración para cada segmento de la vibora.
      snakeVector.at(it).setLastX(xPos);  // Asignamos lo que seria la posición X anterior
      snakeVector.at(it).setLastY(yPos);  // Idem a la posición Y
      if (it > 0) {  // Para todos los segmentos luego del primero (head)...
        lastXPos = snakeVector.at(it-1).getLastX();
        lastYPos = snakeVector.at(it-1).getLastY();
        snakeVector.at(it).setX(lastXPos);  // Le pasamos la posición X anterior del de adelante a la actual.
        snakeVector.at(it).setY(lastYPos);  // Idem a la pos Y
      } else {  // Para el primer segmento (head)...
        snakeVector.at(it).modifyHeadPos(curMovement);  // Leemos curMovement y asignamos la dirección
      }
      Movement::printSegmentsTick (snakeVector, it); // Imprimimos cada segmento al final de cada iteración, luego de mover las posiciones correspondientes.
    }
  }
}
