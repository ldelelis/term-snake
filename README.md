# term-snake
It's snake, for GNU/Linux terminals. This project is a "learn by making" kind of deal, so don't expect any professionalism from it.

## Dependencies
- ncurses

As far as I know that's it (besides obviously a C++ compiler, but that should go without saying).

## Getting a copy
Until I manage to create a decent Makefile:
```
git clone https://github.com/ldelelis/term-snake
cd term-snake
mkdir bin
g++ -Wall -g -lncurses -I ../include -std=c++11 -o ../bin/run ../src/*.cpp *.hpp
```
And then just execute the run file generated in the bin/ directory.

## License
term-snake is licensed under the **Do What The Fuck You Want Public License (wtfpl)**. 

Seriously, it's not like I'm reinventing management systems here. Just do what you feel like with this.
