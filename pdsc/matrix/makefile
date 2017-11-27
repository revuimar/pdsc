testmatrix: testmatrix.o matrix.o exceptions.o
	g++ -g $^ -o $@

matrix.o: matrix.cpp matrix.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

testmatrix.o: testmatrix.cpp matrix.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

exceptions.o: exceptions.cpp matrix.h
	g++ -g -c -Wall -pedantic -std=c++11 $< -o $@

.PHONY: clean

clean:
	-rm matrix.o testmatrix.o exceptions.o testmatrix