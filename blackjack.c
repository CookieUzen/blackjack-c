#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

const int playerCount = 1;

// deck of card, with card values
// spade, club, heart, diamonds
char cards[4][13] = { 
	{'a',2,3,4,5,6,7,8,9,10,10,10},
	{'a',2,3,4,5,6,7,8,9,10,10,10},
	{'a',2,3,4,5,6,7,8,9,10,10,10},
	{'a',2,3,4,5,6,7,8,9,10,10,10},
};

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
void printStatus ( Player * player, int index );

int main () {
	// Setting up random number generator
	srand(time(NULL));

	// Creating Player Pool
	Player player[playerCount];

	// Creating Dealer Player
	newPlayer(player, 0, "dealer");

	int round = 0;
	// Dealer Loop
	while ( 1 ) {
		int dealerCount = addAce(player,0);
		printf("Your current card count is %d\n", dealerCount);

		// Dealer Logic
		if ( dealerCount <= 16 ) 
			printf("\nYou have drawn a %d\n", addCard(player, 0, round));
		else if ( dealerCount > 21 ) {
			printf("%d, BUST!\n", dealerCount);
			break;
		}
		else {
			printf("Final Value: %d\n", dealerCount);
			break;
		}

		round++;
	}

	printStatus();
}

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

void printStatus ( Player * player, int index ) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 12; j++) {
			printf("%d, ", player[0].deck[i][j]);
		}
		printf("\n");
	}
}
