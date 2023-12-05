CC=g++
CFLAGS=-Wall -g

COMPILE_COMMAND=$(CC) $(CFLAGS)

all: main.exe

main.exe: main.o utility.o Game_card.o Game_processor.o
	$(COMPILE_COMMAND) -o main.exe main.o utility.o Game_card.o Game_processor.o

main.o: main.cpp utility.h Game_card.h Game_processor.h
	$(COMPILE_COMMAND) -c main.cpp 

utility.o: utility.cpp utility.h
	$(COMPILE_COMMAND) -c utility.cpp

Game_processor.o: Game_processor.cpp Game_processor.h Game_card.h
	$(COMPILE_COMMAND) -c Game_processor.cpp

Game_card.o: Game_card.cpp Game_card.h
	$(COMPILE_COMMAND) -c Game_card.cpp

clean:
	rm main.o main.exe utility.o Game_card.o
