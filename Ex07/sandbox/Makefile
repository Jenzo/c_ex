all: overhead.o stopwatch.o
	g++ stopwatch.o overhead.o -o allcalls
	
overhead.o: overhead.cpp
	g++ -c overhead.cpp -DVERBOSE
	
task02: stopwatch.o task02.o
	g++ stopwatch.o overhead.o -o overhead
	
task02.o: overhead.cpp
	g++ -c overhead.cpp -DTASK02
	
stopwatch.o: stopwatch.cpp
	g++ -c stopwatch.cpp
	
task03: task03.o
	g++ overhead.o -o casting 
	
task03.o: overhead.cpp
	g++ -c overhead.cpp -DTASK03

clean:
	del *.o *.exe