CC=g++
CFLAGS=-Wall

COMPILE_COMMAND=$(CC) $(CFLAGS)

all: main.exe

main.exe: main.o
	$(COMPILE_COMMAND) -o main.exe main.o 

main.o: main.cpp
	$(COMPILE_COMMAND) -c main.cpp 

clean:
	rm main.o main.exe
