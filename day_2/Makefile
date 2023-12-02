CC=g++
CFLAGS=-Wall

COMPILE_COMMAND=$(CC) $(CFLAGS)

all: main.exe

main.exe: main.o game.o
	$(COMPILE_COMMAND) -o main.exe main.o game.o

main.o: main.cpp game.h
	$(COMPILE_COMMAND) -c main.cpp 

game.o: game.cpp game.h
	$(COMPILE_COMMAND) -c game.cpp

clean:
	rm main.o main.exe game.o
