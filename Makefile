DEPS:=init.hpp snake.hpp
DEPSDIR=./include/

CC=g++
CXXFLAGS=-lncurses -I$(DEPSDIR)

SRC=main.cpp
SRCDIR=./src/

TARGET=run
TGDIR=./bin/

OBJDIR=./build/

$(OBJDIR)/%.o: $(SRCDIR)$(SRC)
	$(CC) $(CXXLFAGS) -c -o $(OBJDIR)$@ $< 

run: $(SRCDIR)$(SRC) 
	$(CC) $(CXXFLAGS) $(DEPSDIR)init.hpp $(DEPSDIR)snake.hpp $(SRCDIR)$(SRC) -o $(TGDIR)$(TARGET) 
