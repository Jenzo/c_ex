all: main.o
	g++ main.o -o helloext -std=c++11

main.o: main.cpp
	g++ -c main.cpp
		
clean: 
	rm *.o helloext		