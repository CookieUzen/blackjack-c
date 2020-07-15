# Makefile

CC = gcc 
TARGET = blackjack
FILES = blackjack.c player.c
EXE = blackjack

build:
	$(CC) $(FILES) -o $(EXE)

run:
	$(CC) $(FILES) -o $(EXE) && ./$(EXE)

clean:
	rm $(TARGET)
