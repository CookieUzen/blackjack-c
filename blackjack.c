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
} Player;

void newPlayer ( Player * player, int index, char playerName[] );
int addCard ( Player * player, int index );
int drawCard ();
int addAce ( Player * player, int index );

int main () {
	// Setting up random number generator
	srand(time(NULL));

	// Creating Player Pool
	Player player[playerCount];

	// Creating Dealer Player
	newPlayer(player, 0, "dealer");

	// Dealer Loop
	while ( 1 ) {
		int dealerCount = addAce(player,0);
		printf("Your current card count is %d\n", dealerCount);

		// Dealer Logic
		if ( dealerCount <= 16 ) 
			printf("\nYou have drawn a %d\n", addCard(player, 0));
		else if ( dealerCount > 21 ) {
			printf("%d, BUST!", dealerCount);
			exit(0);
		}
		else {
			printf("Final Value: %d\n", dealerCount);
			exit(0);
		}
	}
}

void newPlayer ( Player * player, int index, char playerName[] ) {
	player[index].count = 0;
	player[index].ace = 0;
	strcpy(player[index].playerName, playerName);
}

int drawCard () {
	int selection, i, j;
	do {
		i = rand() % 13;
		j = rand() % 4;
		selection = cards[i][j];
	} while ( selection == 0 );

	cards[i][j] = 0;
	return selection;
}

int addCard ( Player * player, int index ) {
	int number = drawCard();

	printf("%d",number);
	
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
