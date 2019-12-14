all: main.o
	gcc main.o -o proportional -ljpeg

main.o: main.c
	gcc -c main.c -ljpeg	
	
clean: 
	rm *.o proportional