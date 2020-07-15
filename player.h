#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Player {
	char playerName[50]; // player name
	int turn;            // played in round or not
	int count;           // amount in hand without accounting ace
	int ace;             // amount of ace in hand
	char deck[2][12];    // 0 for card name, 1 for card value
} Player;

void newPlayer ( Player * player, int index, char playerName[] );
int addCard ( Player * player, int index, int cardNum );
int addAce ( Player * player, int index );

#endif
