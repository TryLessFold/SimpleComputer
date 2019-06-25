
.PHONY: clean build lib

all: clean build base

base: main.o
	gcc build/main.o -Llib -lmy -o sim_com

main.o: src/main.c
	gcc src/main.c -I includes -Llib -lmy -c -o build/main.o

lib: clean build
	gcc src_lib/*.c -c -I includes
	ar rc lib/lib${LIB_NAME}.a *.o

build:
	mkdir build/

clean:
	rm -rf build/
	rm -f *.o

