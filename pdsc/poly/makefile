testpoly: testpoly.o poly.o
	g++ -g $^ -o $@

poly.o: poly.cpp poly.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

testpoly.o: testpoly.cpp poly.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

.PHONY: clean

clean:
	-rm poly.o testpoly.o testpoly