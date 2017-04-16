DEPS=init.hpp snake.hpp movement.hpp
DEPSDIR=./include/

CXX=g++
CXXFLAGS=-Wall -Wextra -g -lncurses
CXXINC= -I $(DEPSDIR)

SRCS=main.cpp movement.cpp init.cpp snake.cpp
SRCDIR=src/

TARGET=run
TGDIR=./bin/

OBJDIR=./build/
OBJS=$(SRCS:.cpp=.o)

run: objects
	cd $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(wildcard $(OBJDIR)*) -o $@
	cd -

objects:
	mkdir build/
	for file in $(SRCDIR)*; do \
		$(CXX) -c $$file $(CXXINC); \
	done
	cd -
	mv *.o $(OBJDIR)

clean:
	rm build/ -rf
