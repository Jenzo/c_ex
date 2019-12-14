all: main.o
	gcc main.o -o imageresize -ljpeg

main.o: main.c
	gcc -c main.c	
	
clean: 
	rm *.o imageresize	