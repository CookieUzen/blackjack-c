#include "player.h"

#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED

#include <stdio.h>
#include <unistd.h>

void printStatus ( Player * player, int index );

extern char cards[4][13];
extern int playerCount;

#endif
