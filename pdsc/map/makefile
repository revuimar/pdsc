testmap: testmap.o map.o list.o
	g++ -g $^ -o $@

map.o: map.cpp map.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

testmap.o: testmap.cpp map.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

list.o: list.cpp list.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

.PHONY: clean

clean:
	-rm map.o testmap.o list.o testmap