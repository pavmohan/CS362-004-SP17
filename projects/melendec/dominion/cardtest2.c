#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

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


	G.hand[thisPlayer][0] = adventurer;;
    G.hand[thisPlayer][1] = estate;
    G.hand[thisPlayer][2] = duchy;
    G.hand[thisPlayer][3] = province;
    G.hand[thisPlayer][4] = copper;

    int handNum = G.handCount[thisPlayer];
    G.deckCount[thisPlayer] = 10;
    int discardCount = G.discardCount[thisPlayer];

    int deckCounter = G.deckCount[thisPlayer];
    G.deck[thisPlayer][deckCounter - 1] = council_room;
    G.deck[thisPlayer][deckCounter - 2] = feast;
    G.deck[thisPlayer][deckCounter - 3] = gardens;
    G.deck[thisPlayer][deckCounter - 4] = silver;
    G.deck[thisPlayer][deckCounter - 5] = gold;
    G.deck[thisPlayer][deckCounter - 6] = mine;
    G.deck[thisPlayer][deckCounter - 7] = remodel;
    G.deck[thisPlayer][deckCounter - 8] = smithy;
    G.deck[thisPlayer][deckCounter - 9] = village;
    G.deck[thisPlayer][deckCounter - 10] = baron;

    int t1 = silver;
    int t2 = gold;

    int d1 = council_room;
    int d2 = feast;
    int d3 = gardens;

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

    printf("Discard after effect\n");
    for(i = 0; i < testG.discardCount[thisPlayer]; i++) {
        printf("Discard at pos %d: %d\n", i,testG.discard[thisPlayer][i]);
    }

    printf("Case 1: Deck has two cards\n");
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 1;
    int c5 = 1;


    for(i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == t1) {
            c1 = 1;
        }
        if (testG.hand[thisPlayer][i] == t2) {
            c2 = 1;
        }
    }

    if (c1&&c2) {
        printf("Two treasure cards removed from deck: PASS\n");
    } else {
        printf("Two treasure cards removed from deck: FAIL\n");
    }

    c1 = 1;
    c2 = 1;
    c3 = 1;
    for(i = 0; i < testG.deckCount[thisPlayer]; i++) {
        if (testG.deck[thisPlayer][i] == d1) {
            c1 = 0;
        }
        if (testG.deck[thisPlayer][i] == d2) {
            c2 = 0;
        }
        if (testG.deck[thisPlayer][i] == d3) {
            c3 = 0;
        }
        if (testG.deck[thisPlayer][i] == t1) {
            c4 = 0;
        }
        if (testG.deck[thisPlayer][i] == t2) {
            c5 = 0;
        }
    }

    if (c1&&c2&&c3&&c4&&c5) {
        printf("Two treasure cards and cards before it removed from deck: PASS\n");
    } else {
        printf("Two treasure cards and cards before it removed from deck: FAIL\n");
    }

    c1 = 0; c2 =0; c3 =0;
    for(i = 0; i < testG.discardCount[thisPlayer]; i++) {
        if (testG.discard[thisPlayer][i] == d1) {
            c1 = 1;
        }
        if (testG.discard[thisPlayer][i] == d2) {
            c2 = 1;
        }
        if (testG.discard[thisPlayer][i] == d3) {
            c3 = 1;
        }

    }

    if (c1&&c2&&c3) {
        printf("Revealed cards in discard: PASS\n");
    } else {
        printf("Revealed cards in discard: FAIL\n");
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
