all: base
	rm *.o 

base: processor.o display.o main.c processor.h display.h
	g++ processor.o display.o main.c -o base_prog

processor.o: processor.c 
	g++ -c processor.c

display.o: display.c 
	g++ -c display.c
