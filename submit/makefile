screen.x:  screen.o getChar.o freePool.o worm.o cell.o
	g++ -std=c++11 -ggdb -o screen.x screen.o getChar.o freePool.o worm.o cell.o -lcurses -ltermcap

screen.o: screen.cpp
	g++ -std=c++11 -c -ggdb screen.cpp -o screen.o

getChar.o: getChar.cpp 
	gcc -std=c++11 -c -ggdb getChar.cpp -o getChar.o

freePool.o: freePool.cpp freePool.hpp
	g++ -std=c++11 -c -ggdb freePool.cpp -o freePool.o

worm.o: worm.cpp worm.hpp
	g++ -std=c++11 -c -ggdb worm.cpp -o worm.o

cell.o: cell.cpp cell.hpp
	g++ -std=c++11 -c -ggdb cell.cpp -o cell.o

clean:
	/bin/rm -f screen.x screen.o getChar.o *~
