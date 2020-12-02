CFLAGS=-Wall -pedantic -std=c++11
		
compile: main.o ./fparser4.5.2/fparser.o Algorithm.o AlgorithmTest.h Function.o FunctionTest.h Gradient.o MinimumsList.o Point.o TestPoint.o VectorN.o
	g++ $(CFLAGS) main.o ./fparser4.5.2/examples/fparser.o Algorithm.o Function.o FunctionTest.h AlgorithmTest.h Gradient.o MinimumsList.o Point.o TestPoint.o VectorN.o -o Search

fparser.o: ./fparser4.5.2/fparser.cc ./fparser4.5.2/fparser.hh
	g++ ./fparser4.5.2/fparser.cc ./fparser4.5.2/fparser.hh

main.o: main.cpp
	g++ -c $(CFLAGS) main.cpp

Algorithm.o: Algorithm.cpp Algorithm.h
	g++ -c $(CFLAGS) Algorithm.cpp Algorithm.h

Function.o: Function.cpp Function.h
	g++ -c $(CFLAGS) Function.cpp Function.h

Gradient.o: Gradient.cpp Gradient.h 
	g++ -c $(CFLAGS) Gradient.cpp Gradient.h

MinimumsList.o: MinimumsList.cpp MinimumsList.h
	g++ -c $(CFLAGS) MinimumsList.cpp MinimumsList.h

Point.o: Point.cpp Point.h
	g++ -c $(CFLAGS) Point.cpp Point.h

TestPoint.o: TestPoint.cpp TestPoint.h
	g++ -c $(CFLAGS) TestPoint.cpp TestPoint.h

VectorN.o: VectorN.cpp VectorN.h
	g++ -c $(CFLAGS) VectorN.cpp VectorN.h

clear:
	rm -rf *o *gch Search
