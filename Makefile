GCC = gcc -Wall -Werror
OBJ = build/processor.o build/display.o
HEAD = src/processor.h src/display.h

.PHONY: clean 

all: bin build default

default: bin/SimpleComputer

bin/SimpleComputer: build/main.o $(OBJ)
	$(GCC) -std=c99 build/main.o $(OBJ) -o bin/SimpleComputer

build/processor.o: src/processor.c src/processor.h
	$(GCC) -std=c99 -c src/processor.c -o build/processor.o

build/display.o: src/display.c src/display.h
	$(GCC) -std=c99 -c src/display.c -o build/display.o

build/main.o: src/main.c $(HEAD)
	$(GCC) -c src/main.c -o build/main.o 

bin:
	mkdir bin

build:
	mkdir build

clean: 
	rm -rf bin build
