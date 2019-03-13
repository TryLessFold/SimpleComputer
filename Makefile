all: base
	rm *.o 

base: processor.o display.o main.o
	gcc processor.o display.o main.o -std=c99 -o base_prog

main.o: main.c
	gcc -c -std=c99 main.c

processor.o: processor.c processor.h
	gcc -c -std=c99 processor.c

display.o: display.c display.h
	gcc -c -std=c99 display.c
