CC=g++
CFLAGS=-Wall -g

COMPILE_COMMAND=$(CC) $(CFLAGS)

all: main.exe

main.exe: main.o utility.o Engine_coordinate.o
	$(COMPILE_COMMAND) -o main.exe main.o utility.o Engine_coordinate.o

main.o: main.cpp utility.h Engine_coordinate.h
	$(COMPILE_COMMAND) -c main.cpp 

utility.o: utility.cpp utility.h
	$(COMPILE_COMMAND) -c utility.cpp

Engine_coordinate.o: Engine_coordinate.cpp Engine_coordinate.h
	$(COMPILE_COMMAND) -c Engine_coordinate.cpp

clean:
	rm main.o main.exe utility.o Engine_coordinate.o
