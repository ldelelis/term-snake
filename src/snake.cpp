#include "snake.hpp"

void printSegmentsTick (std::string snakeVector, int it) {
  mvprintw(snakeVector.at(it).yPos, snakeVector.at(it).xPos, snakeVector.segment); //Imprimimos el segmento en la posición avanzada...
  mvprintw(snakeVector.at(it).lastXpos, snakeVector.at(it).lastYpos, " \r"); // Y borramos el leftover en la posición anterior.
}

void moveSegmentsTick (std::vector snakeVector) {
  int it=0;    // Inicializamos el iterador en el indice 0.
  for (it; it<=snakeVector.size(); it++) {    // Arrancamos la iteración para cada segmento de la vibora.
    snakeVector.at(it).lastXPos = vibora.at(it).xPos;  // Asignamos lo que seria la posición X anterior
    snakeVector.at(it).lastYPos = vibora.at(it).yPos;  // Idem a la posición Y
    if (it > 0) {  // Para todos los segmentos luego del primero (head)...
      snakeVector.at(it).xPos = snakeVector.at(it-1).lastXPos;  // Le pasamos la posición X anterior del de adelante a la actual.
      snakeVector.at(it).yPos = snakeVector.at(it-1).lastYPos;  // Idem a la pos Y
    } else {  // Para el primer segmento (head)...
      this.moveHead(curMovement);  // Leemos curMovement y asignamos la dirección
    }
    printSegmentsTick (snakeVector, it); // Imprimimos cada segmento al final de cada iteración, luego de mover las posiciones correspondientes.
  }
}

void moveHead (char curMovement) {    // Determinamos el movimiento segun la dirección actual.
  switch (curMovement) {
  case 'u':   // Arriba
      this.decrementY();
      break;
  case 'd':   // Abajo
      this.incrementY();
      break;
  case 'l':   // Izquierda
      this.decrementX();
      break;
  case 'r':   // Derecha
      this.incrementX();
      break;
  }
}
