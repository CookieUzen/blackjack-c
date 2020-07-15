#include "player.h"
#include "blackjack.h"

void newPlayer ( Player * player, int index, char playerName[] ) {
	player[index].count = 0;
	player[index].ace = 0;
	strcpy(player[index].playerName, playerName);

	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 12; j++) 
			player[index].deck[i][j] = 0;
}

int addCard ( Player * player, int index, int cardNum ) {
	int selection, i, j;
	do {
		i = rand() % 4;
		j = rand() % 13;
		selection = cards[i][j];
	} while ( selection == 0 );

	cards[i][j] = 0;
	int number = selection;

	player[index].deck[0][cardNum] = i + 1;
	player[index].deck[1][cardNum] = j + 1;
	
	if ( (char) number == 'a' )
		player[index].ace ++;
	else 
		player[index].count += number;

	return number;
}

int addAce ( Player * player, int index ) {
	int count = player[index].count;
	int aceCount = player[index].ace;

	if ( aceCount == 0 ) 
		return count;
	if ( count <= 11-aceCount ) 
		return count + 10 + aceCount;
	else
		return count + aceCount;
}

