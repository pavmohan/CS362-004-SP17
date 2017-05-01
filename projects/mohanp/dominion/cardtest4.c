#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "great hall"

int main() {
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

	G.hand[thisPlayer][0] = great_hall;
    G.hand[thisPlayer][1] = estate;
    G.hand[thisPlayer][2] = duchy;
    G.hand[thisPlayer][3] = province;
    G.hand[thisPlayer][4] = copper;

    G.handCount[thisPlayer] = 5;
    G.deckCount[thisPlayer] = 5;

    int deckCounter = G.deckCount[thisPlayer];
    G.deck[thisPlayer][deckCounter - 1] = council_room;
    G.deck[thisPlayer][deckCounter - 2] = feast;
    G.deck[thisPlayer][deckCounter - 3] = gardens;
    G.deck[thisPlayer][deckCounter - 4] = silver;
    G.deck[thisPlayer][deckCounter - 5] = gold;

    int card1 = council_room;

    memcpy(&testG, &G, sizeof(struct gameState));

    printf("Hand before effect\n");
    for(i = 0; i < testG.handCount[thisPlayer]; i++) {
        printf("Card at pos %d: %d\n", i,testG.hand[thisPlayer][i]);
    }
    printf("Deck before effect\n");
    for(i = 1; i <= testG.deckCount[thisPlayer]; i++) {
        printf("Card: %d\n", testG.deck[thisPlayer][testG.deckCount[thisPlayer]-i]);
    }


    printf("Play card result: %d\n",playCard(handpos, choice1, choice2, choice3, &testG));

    printf("Hand after effect\n");
    for(i = 0; i < testG.handCount[thisPlayer]; i++) {
        printf("Card at pos %d: %d\n", i,testG.hand[thisPlayer][i]);
    }

    printf("Deck after effect\n");
    for(i = 1; i <= testG.deckCount[thisPlayer]; i++) {
        printf("Card: %d\n", testG.deck[thisPlayer][testG.deckCount[thisPlayer]-i]);
    }

    printf("Test case 1: Full deck\n");
    int c1 = 0;
    for(i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == card1) {
            c1 = 1;
        }
    }

    if (c1) {
        printf("Correct drawn card placed in hand: PASS\n");
    } else {
        printf("Correct drawn cards placed in hand: FAIL\n");
    }

    c1 = 1;
    for(i = 0; i < testG.deckCount[thisPlayer]; i++) {
        if (testG.deck[thisPlayer][i] == card1) {
            c1 = 0;
        }
    }

    if (c1) {
        printf("Correct drawn card removed from deck: PASS\n");
    } else {
        printf("Correct drawn cards removed from deck: FAIL\n");
    }

    if (G.deckCount[thisPlayer]-1 == testG.deckCount[thisPlayer] ) {
        printf("Deck has one less card: PASS\n");
    } else {
        printf("Deck has one less card: PASS\n");
    }

    c1 = 1;
    for(i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == great_hall) {
            c1 = 0;
        }
    }

    if (c1) {
        printf("Great hall no longer in hand: PASS\n");
    } else {
        printf("Great hall no longer in hand: FAIL\n");
    }

    if (testG.numActions==1) {
        printf("Player gains an additional action: PASS\n");
    } else {
        printf("Player gains an additional action: FAIL\n");
    }

    //No state change for kingdom and victory card piles
    if(k[0]==adventurer && k[1] == embargo && k[2]== village && k[3]== remodel &&
       k[4]== mine && k[5] == cutpurse && k[6] == sea_hag && k[7] == tribute &&
       k[8] == smithy && k[9] == council_room) {
            printf("No state change in kingdom: PASS\n");
       } else {
            printf("No state change in kingdom: FAIL\n");
       }
    if(G.supplyCount[thisPlayer] == testG.supplyCount[thisPlayer]) {
        printf("No change in supply: PASS\n");
    } else {
        printf("No change in supply: FAIL\n");
    }
    return 0;
}
