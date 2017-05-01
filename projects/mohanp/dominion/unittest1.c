#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main()
{
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, remodel, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));


	if(testG.numPlayers==2) {
        printf("Number of players correct: PASS\n");
	} else {
        printf("Number of players correct: FAIL\n");
	}
	if(testG.supplyCount[curse] == 10) {
        printf("Number of curses correct: PASS\n");
	} else {
        printf("Number of curses correct: FAIL\n");
	}
	if(testG.supplyCount[estate] == 8) {
        printf("Number of estate correct: PASS\n");
	} else {
        printf("Number of estate correct: FAIL\n");
	}
	if(testG.supplyCount[duchy] == 8) {
        printf("Number of duchy correct: PASS\n");
	} else {
        printf("Number of duchy correct: FAIL\n");
	}
	if(testG.supplyCount[province] == 8) {
        printf("Number of province correct: PASS\n");
	} else {
        printf("Number of province correct: FAIL\n");
	}
	if(testG.supplyCount[copper] == 46) {
        printf("Number of copper correct: PASS\n");
	} else {
        printf("Number of copper correct: FAIL\n");
	}
	if(testG.supplyCount[silver] == 40) {
        printf("Number of silver correct: PASS\n");
	} else {
        printf("Number of silver correct: FAIL\n");
	}
	if(testG.supplyCount[gold] == 30) {
        printf("Number of gold correct: PASS\n");
	} else {
        printf("Number of gold correct: FAIL\n");
	}
	if(testG.whoseTurn== 0) {
        printf("Player 0 starts correct: PASS\n");
	} else {
        printf("Player 0 starts correct: FAIL\n");
	}
	if(testG.numActions== 1) {
        printf("Action count correct: PASS\n");
	} else {
        printf("Action count correct: FAIL\n");
	}
	if(testG.numBuys== 1) {
        printf("Buy count correct: PASS\n");
	} else {
        printf("Buy count correct: FAIL\n");
	}

	if(testG.discardCount[0]== 0) {
        printf("Player 0 Discard count correct: PASS\n");
	} else {
        printf("Player 0 Discard count correct: FAIL\n");
	}
	if(testG.discardCount[1]== 0) {
        printf("Player 1 Discard count correct: PASS\n");
	} else {
        printf("Player 1 Discard count correct: FAIL\n");
	}

    int cCount = 0;
    int eCount = 0;
    for( i = 0; i < testG.handCount[thisPlayer]; i++) {
        if(testG.hand[thisPlayer][i]==copper) {
            cCount++;
        } else if (testG.hand[thisPlayer][i]==estate) {
            eCount++;
        }

    }
    for( i = 0; i < testG.deckCount[thisPlayer]; i++) {
        if(testG.deck[thisPlayer][i]==copper) {
            cCount++;
        } else if (testG.deck[thisPlayer][i]==estate) {
            eCount++;
        }

    }
    if(cCount== 7) {
        printf("Player 0 copper count correct: PASS\n");
	} else {
        printf("Player 0 copper count correct: FAIL\n");
	}

	if(eCount== 3) {
        printf("Player 0 estate count correct: PASS\n");
	} else {
        printf("Player 0 estate count correct: FAIL\n");
	}
    thisPlayer++;

    cCount = 0;
    eCount = 0;
    for( i = 0; i < testG.handCount[thisPlayer]; i++) {
        if(testG.hand[thisPlayer][i]==copper) {
            cCount++;
        } else if (testG.hand[thisPlayer][i]==estate) {
            eCount++;
        }

    }
    for( i = 0; i < testG.deckCount[thisPlayer]; i++) {
        if(testG.deck[thisPlayer][i]==copper) {
            cCount++;
        } else if (testG.deck[thisPlayer][i]==estate) {
            eCount++;
        }

    }
    if(cCount== 7) {
        printf("Player 1 copper count correct: PASS\n");
	} else {
        printf("Player 1 copper count correct: FAIL\n");
	}

	if(eCount== 3) {
        printf("Player 1 estate count correct: PASS\n");
	} else {
        printf("Player 1 estate count correct: FAIL\n");
	}

	if(testG.handCount[thisPlayer]==0) {
        printf("Player 1 hand count correct: PASS\n");
	} else {
	    printf("Player 1 hand count correct: FAIL\n");
	}

	if(testG.playedCardCount==0) {
        printf("Played card count correct: PASS\n");
	} else {
	    printf("Played card count correct: FAIL\n");
	}

	if(testG.deckCount[thisPlayer]==10) {
        printf("Player 1 deck count correct: PASS\n");
	} else {
	    printf("Player 1 deck count correct: FAIL\n");
	}
	thisPlayer--;

	if(testG.deckCount[thisPlayer]==5) {
        printf("Player 1 deck count correct: PASS\n");
	} else {
	    printf("Player 1 deck count correct: FAIL\n");
	}
    return 0;

}
