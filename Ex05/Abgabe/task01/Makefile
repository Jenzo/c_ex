all: stacksimpletest.o
	g++ stacksimpletest.o -o stack -std=c++11

stacksimpletest.o: stacksimpletest.cpp
	g++ -c stacksimpletest.cpp -c stack.cpp -c stack.hpp
		
clean: 
	rm *.o stack		