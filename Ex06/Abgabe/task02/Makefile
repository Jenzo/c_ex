all: secarrtest.o secarr.o
	g++ secarrtest.o secarr.o -o secarray

secarrtest.o: secarrtest.cpp
	g++ -c secarrtest.cpp
	
secarr.o: secarr.cpp
	g++ -c secarr.cpp	
		
clean: 
	rm *.o secarray	