#include "player.h"

#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED

#include <stdio.h>

void printStatus ( Player * player, int index );

// deck of card, with card values
// spade, club, heart, diamonds
extern char cards[4][13];
#endif
