#testmap: map.cpp testmap.cpp list.cpp
#	g++ -g -Wall -pedantic -Werror -std=c++11 map.cpp testmap.cpp list.cpp -lm
#clean:
#	-rm testmap
testmap: testmap.o map.o list.o
	g++ -g $^ -o $@

list.o: list.cpp list.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

map.o: map.cpp map.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

testmap.o: testmap.cpp map.h aux.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

.PHONY: clean

clean:
	-rm map.o testmap.o list.o testmap