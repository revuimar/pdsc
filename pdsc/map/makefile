#testmap: map.cpp testmap.cpp list.cpp
#	g++ -g -Wall -pedantic -Werror -std=c++11 map.cpp testmap.cpp list.cpp -lm
#clean:
#	-rm testmap
testmap: testmap.o
	g++ -g $^ -o $@

testmap.o: testmap.cpp list.h map.h aux.h library.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

.PHONY: clean

clean:
	-rm map.o testmap.o testmap