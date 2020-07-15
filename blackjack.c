#include "blackjack.h"
#include "player.h"

const int playerCount = 1;

char cards[4][13] = { 
	{'a',2,3,4,5,6,7,8,9,10,10,10},
	{'a',2,3,4,5,6,7,8,9,10,10,10},
	{'a',2,3,4,5,6,7,8,9,10,10,10},
	{'a',2,3,4,5,6,7,8,9,10,10,10},
};

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

	printStatus(player, 0);
}

void printStatus ( Player * player, int index ) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 12; j++) {
			printf("%d, ", player[0].deck[i][j]);
		}
		printf("\n");
	}
}
