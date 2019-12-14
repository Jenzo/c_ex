all: scope1.o scope2.o
	gcc scope1.o scope2.o -o scope

scope1.o: scope1.c
	gcc -c scope1.c
	
scope2.o: scope2.c 
	gcc -c scope2.c
		
clean: 
	rm *.o scope		