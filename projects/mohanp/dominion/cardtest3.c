
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "sea_hag"

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


	G.hand[thisPlayer][0] = sea_hag;
    G.hand[thisPlayer][1] = estate;
    G.hand[thisPlayer][2] = duchy;
    G.hand[thisPlayer][3] = province;
    G.hand[thisPlayer][4] = copper;

    G.deckCount[thisPlayer] = 5;
    int deckCounter = G.deckCount[thisPlayer];

    G.deck[thisPlayer][deckCounter - 1] = council_room;
    G.deck[thisPlayer][deckCounter - 2] = feast;
    G.deck[thisPlayer][deckCounter - 3] = gardens;
    G.deck[thisPlayer][deckCounter - 4] = silver;
    G.deck[thisPlayer][deckCounter - 5] = gold;

    thisPlayer = thisPlayer + 1;
    G.handCount[1] = 5;
    G.hand[1][0] = sea_hag;
    G.hand[1][1] = estate;
    G.hand[1][2] = duchy;
    G.hand[1][3] = province;
    G.hand[1][4] = copper;

    G.deckCount[thisPlayer] = 5;
    deckCounter = G.deckCount[thisPlayer];

    G.deck[thisPlayer][deckCounter - 1] = council_room;
    G.deck[thisPlayer][deckCounter - 2] = feast;
    G.deck[thisPlayer][deckCounter - 3] = gardens;
    G.deck[thisPlayer][deckCounter - 4] = silver;
    G.deck[thisPlayer][deckCounter - 5] = gold;

    thisPlayer = thisPlayer - 1;


	memcpy(&testG, &G, sizeof(struct gameState));
    printf("1 Hand before effect\n");
    for(i = 0; i < testG.handCount[thisPlayer]; i++) {
        printf("Card at pos %d: %d\n", i,testG.hand[thisPlayer][i]);
    }
    printf(" 1 Deck before effect\n");
    for(i = 1; i <= testG.deckCount[thisPlayer]; i++) {
        printf("Card: %d\n", testG.deck[thisPlayer][testG.deckCount[thisPlayer]-i]);
    }

    thisPlayer = thisPlayer+1;

    printf("2 Hand before effect\n");
    for(i = 0; i < testG.handCount[1]; i++) {
        printf("Card at pos %d: %d\n", i,testG.hand[1][i]);
    }
    printf(" 2 Deck before effect\n");
    for(i = 1; i <= testG.deckCount[1]; i++) {
        printf("Card: %d\n", testG.deck[1][testG.deckCount[1]-i]);
    }
    thisPlayer = thisPlayer -1;

    printf("Play card result: %d\n",playCard(handpos, choice1, choice2, choice3, &testG));

   printf("1 Hand after effect\n");
    for(i = 0; i < testG.handCount[thisPlayer]; i++) {
        printf("Card at pos %d: %d\n", i,testG.hand[thisPlayer][i]);
    }

    printf("1 Deck after effect\n");
    for(i = 1; i <= testG.deckCount[thisPlayer]; i++) {
        printf("Card: %d\n", testG.deck[thisPlayer][testG.deckCount[thisPlayer]-i]);
    }

    printf("1 Discard after effect\n");
    for(i = 0; i < testG.discardCount[thisPlayer]; i++) {
        printf("Discard at pos %d: %d\n", i,testG.discard[thisPlayer][i]);
    }

    thisPlayer = thisPlayer+1;

    printf("2 Hand after effect\n");
    for(i = 0; i < testG.handCount[1]; i++) {
        printf("Card at pos %d: %d\n", i,testG.hand[1][i]);
    }

    printf("2 Deck after effect\n");
    for(i = 1; i <= testG.deckCount[1]; i++) {
        printf("Card: %d\n", testG.deck[1][testG.deckCount[1]-i]);
    }

    printf("2 Discard after effect\n");
    for(i = 0; i < testG.discardCount[1]; i++) {
        printf("Discard at pos %d: %d\n", i,testG.discard[1][i]);
    }

    thisPlayer = thisPlayer -1;

    printf("Top card of other player: %d\n",testG.deck[1][testG.deckCount[1]-1] );

    int c1 = 1;
    for(i = 0; i < testG.handCount[0]; i++) {
        if(testG.hand[0][i] != G.hand[0][i]) {
            c1 = 0;
        }
    }
    for(i = 0; i < testG.deckCount[0]; i++) {
        if(testG.deck[0][i] != G.deck[0][i]) {
            c1 = 0;
        }
    }
    if(c1) {
        printf("Player 0's hand and deck not affected by calling sea hag: PASS\n");
    } else {
        printf("Player 0's hand and deck not affected by calling sea hag: FAIL\n");
    }

    c1 = 1;
    for(i = 0; i < testG.handCount[1]; i++) {
        if(testG.hand[1][i] != G.hand[1][i]) {
            c1 = 0;
        }
    }
    if(c1) {
        printf("Player 1's hand not affected by calling sea hag: PASS\n");
    } else {
        printf("Player 1's hand not affected by calling sea hag: FAIL\n");
    }

    if(testG.deck[1][testG.deckCount[1]-1] == curse) {
        printf("Player 1's top card is curse: PASS\n");
    } else {
        printf("Player 1's top card is curse: FAIL\n");
    }

    if(testG.deckCount[1] == G.deckCount[1]) {
        printf("Player 1's deck count stays the same: PASS\n");
    } else {
        printf("Player 1's deck count stays the same: FAIL\n");
    }




    return 0;
}
