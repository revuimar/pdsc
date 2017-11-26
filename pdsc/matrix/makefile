testmatrix: testmatrix.o matrix.o
	g++ -g $^ -o $@

matrix.o: matrix.cpp matrix.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

testmatrix.o: testmatrix.cpp matrix.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

.PHONY: clean

clean:
	-rm matrix.o testmatrix.o testmatrix