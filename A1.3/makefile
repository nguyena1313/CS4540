CC = gcc

#CFLAGS = -g -Wall -pedantic
CFLAGS = -O -Wall -pedantic

Source : Source.o readfile.o interactive.o

Source.o : interactive.h readfile.h structs.h

readfile.o : readfile.h structs.h

interactive.o : structs.h interactive.h

clean:
	rm -f *.o core Source

run: Source
	./Source zip.txt 25
