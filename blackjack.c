#include "blackjack.h"
#include "player.h"

char cards[4][13] = { 
	{'a',2,3,4,5,6,7,8,9,10,10,10},
	{'a',2,3,4,5,6,7,8,9,10,10,10},
	{'a',2,3,4,5,6,7,8,9,10,10,10},
	{'a',2,3,4,5,6,7,8,9,10,10,10},
};

int playerCount;

int main () {

	// Setting up random number generator
	srand(time(NULL));

	// Creating players 
	printf("How many players: ");
	scanf("%d", &playerCount);
	
	if ( ! playerCount > 0 ) {
		printf("OK then :(\n");
		exit(0);
	}

	playerCount++;
	Player player[playerCount];

	printf("\n");

	// Creating Player Pool
	newPlayer(player, 0, "dealer");

	char name[20];
	for (int i = 1; i < playerCount; i++) {
		printf("Player %d Name: ", i);
		scanf("%s",name); 
		newPlayer(player, i, name);
	}

	// List players for debug
	printf("\nPlayer list:\n");

	for (int i = 0; i < playerCount; i++) {
		printf("- %s\n",player[i].playerName);
	}
	printf("\n");

	// Dealer draws first card
	dealerPlayRound(player, 0);
	printf("\n");

	// Players draw card
	for (int i = 1; i < playerCount; i++) {
		printf("%s's turn:\n",player[i].playerName);
		sleep(1);
		printf("You have drawn %d\n\n", addCard(player, i));
		sleep(1);
	}

	// Player asked to draw additional cards
	for (int i = 1; i < playerCount; i++) {
		printf("%s:\n", player[i].playerName);
		while ( 1 ) {
			printf("You have %d in total\n", addAce(player,i));
			printf("Draw Card? (y/n): ");
			char go;
			scanf(" %c", &go);

			if ( go == 'y' ) 
				printf("You have drawn a %d\n", addCard(player, i));
			else
				break;

			if ( addAce(player, i) > 21 ) {
				printf("BUST!\n\n");
				break;
			}
			
			printf("\n");
		}

		player[i].finalScore = addAce(player,i);
		printf("Final Value: %d\n\n", player[i].finalScore);
	}

	// Dealer plays last
	printf("Dealer has %d\n", addAce(player,0));
	while ( 1 ) {
		if ( dealerPlayRound(player,0) != 0 ) 
			break;
	}

	// Check deck for debug: 2nd row is card id
	printf("\nDeck Check!\n");
	for (int i = 0; i < playerCount; i++) {
		printf("%s\n",player[i].playerName);
		printStatus(player,i);
		printf("\n");
	}

	// Check for players that won
	int count;
	if ( player[0].finalScore <= 21 ) {
		for (int i = 1; i < playerCount; i++) {
			if ( player[i].finalScore > player[0].finalScore && player[i].finalScore <= 21 ) {
				printf("%s ",player[i].playerName);
				count++;
			}
		}
	}
	else {
		for (int i = 1; i < playerCount; i++) {
			printf("%s ",player[i].playerName);
			count++;
		}
	}
		
	if ( count != 0 ) 
		printf("wins!\n");
	else
		printf("You LOSE!\n");
	
}

void printStatus ( Player * player, int index ) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 12; j++) {
			printf("%d, ", player[index].deck[i][j]);
		}
		printf("\n");
	}
}
