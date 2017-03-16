CC=g++
CFLAGS=-lncurses
DEPS=init.hpp snake.hpp
OBJ=run
SRC=main.cpp

main.cpp: $(OBJ) $(DEPS)
	$(CC) -o $(OBJ) $(SRC) $(DEPS) $(CFLAGS)
