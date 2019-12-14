all: main.o
	gcc main.o -o bilinear -ljpeg

main.o: main.c
	gcc -c main.c	
	
clean: 
	rm *.o bilinear	