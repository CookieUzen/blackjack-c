# Makefile

CC = gcc 
TARGET = blackjack
FILES = blackjack.c player.c
EXE = blackjack

all:
	$(CC) $(FILES) -o $(EXE)

clean:
	rm $(TARGET)
