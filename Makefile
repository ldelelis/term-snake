DEPS=init.hpp snake.hpp movement.hpp comida.hpp
DEPSDIR=include/

CXX=g++
CXXFLAGS=-Wall -Wextra -g -lncurses -std=c++11
CXXINC= -I $(DEPSDIR)

SRCS=main.cpp movement.cpp init.cpp snake.cpp comida.cpp
SRCDIR=src/

OBJDIR=./build/
OBJS=$(SRCS:.cpp=.o)

run: objects
	cd $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(wildcard $(OBJDIR)*) -o $@
	cd -

objects:
	if [ ! -d "build" ]; then \
		mkdir build/; \
	fi
	for file in $(SRCDIR)*; do \
		$(CXX) -c $$file $(CXXINC); \
	done
	cd -
	mv *.o $(OBJDIR)

clean:
	rm build/ -rf
