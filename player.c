#include "player.h"
#include "blackjack.h"

void newPlayer ( Player * player, int index, char playerName[20] ) {
	player[index].count = 0;
	player[index].ace = 0;
	strcpy(player[index].playerName, playerName);
	player[index].cRound = 0;
	player[index].finalScore = 0;

	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 12; j++) 
			player[index].deck[i][j] = 0;
}

int addCard ( Player * player, int index ) {
	int selection, i, j;
	do {
		i = rand() % 4;
		j = rand() % 13;
		selection = cards[i][j];
	} while ( selection == 0 );

	cards[i][j] = 0;
	int number = selection;

	player[index].deck[0][player[index].cRound] = i + 1;
	player[index].deck[1][player[index].cRound] = j + 1;
	
	// 97 is an ace
	if ( number == 97 )
		player[index].ace ++;
	else 
		player[index].count += number;

	player[index].cRound++;

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

int dealerPlayRound ( Player * player, int index ) {
	int dealerAddition = addAce(player,0);

	sleep(1);

	if ( dealerAddition <= 16 ) 
		printf("Dealers draws a %d\n", addCard(player, 0));
	else if ( dealerAddition > 21 ) {
		printf("%d, BUST!\n", dealerAddition);
		return -1;
	}
	else {
		printf("Final Value: %d\n", dealerAddition);
		player[0].finalScore = dealerAddition;
		return 1;
	}

	return 0;
}
