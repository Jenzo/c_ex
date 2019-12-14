all: timetest.o mytime.o
	g++ timetest.o mytime.o -o mytime

timetest.o: timetest.cpp 
	g++ -c timetest.cpp 
	
mytime.o: mytime.cpp	
	g++ -c mytime.cpp	
	
clean: 
	rm *.o mytime	