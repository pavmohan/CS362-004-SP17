#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 1, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, remodel, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);


	G.hand[thisPlayer][0] = smithy;
    G.hand[thisPlayer][1] = estate;
    G.hand[thisPlayer][2] = duchy;
    G.hand[thisPlayer][3] = province;
    G.hand[thisPlayer][4] = copper;

    int handNum = G.handCount[thisPlayer];
    G.deckCount[thisPlayer] = 10;
    int discardCount = G.discardCount[thisPlayer];

    int deckCounter = G.deckCount[thisPlayer];
    G.deck[thisPlayer][deckCounter - 1] = adventurer;
    G.deck[thisPlayer][deckCounter - 2] = adventurer;
    G.deck[thisPlayer][deckCounter - 3] = adventurer;
    G.deck[thisPlayer][deckCounter - 4] = council_room;
    G.deck[thisPlayer][deckCounter - 5] = feast;
    G.deck[thisPlayer][deckCounter - 6] = gardens;
    G.deck[thisPlayer][deckCounter - 7] = mine;
    G.deck[thisPlayer][deckCounter - 8] = remodel;
    G.deck[thisPlayer][deckCounter - 9] = village;
    G.deck[thisPlayer][deckCounter - 10] = baron;


    int card1 = G.deck[thisPlayer][deckCounter - 1];
    int card2 = G.deck[thisPlayer][deckCounter - 2];
    int card3 = G.deck[thisPlayer][deckCounter - 3];
    int card4 = G.deck[thisPlayer][deckCounter - 4];
    int card5 = G.deck[thisPlayer][deckCounter - 5];
    int card6 = G.deck[thisPlayer][deckCounter - 6];
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

    printf("Deck card: %d\n",card1);
    printf("Deck card: %d\n",card2);
    printf("Deck card: %d\n",card3);
    printf("Deck card: %d\n",card4);
    printf("Deck card: %d\n",card5);
    printf("Deck card: %d\n",card6);



    //Test whether player gets 3 cards
    printf("Case 1: Player chooses to draw 2\n");
    int c1 = 0;
    int c2 = 0;


    for(i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == card1) {
            c1 = 1;
        }
        if (testG.hand[thisPlayer][i] == card2) {
            c2 = 1;
        }
    }

    if (c1&&c2) {
        printf("Correct 2 cards placed in hand: PASS\n");
    } else {
        printf("Correct 2 cards placed in hand: FAIL\n");
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

    printf("Add 2 treasure to count");
    choice1 = 2;
    initializeGame(numPlayers, k, seed, &G);


	G.hand[thisPlayer][0] = smithy;
    G.hand[thisPlayer][1] = estate;
    G.hand[thisPlayer][2] = duchy;
    G.hand[thisPlayer][3] = province;
    G.hand[thisPlayer][4] = copper;

     handNum = G.handCount[thisPlayer];
    G.deckCount[thisPlayer] = 10;
    discardCount = G.discardCount[thisPlayer];

    deckCounter = G.deckCount[thisPlayer];
    G.deck[thisPlayer][deckCounter - 1] = adventurer;
    G.deck[thisPlayer][deckCounter - 2] = adventurer;
    G.deck[thisPlayer][deckCounter - 3] = adventurer;
    G.deck[thisPlayer][deckCounter - 4] = council_room;
    G.deck[thisPlayer][deckCounter - 5] = feast;
    G.deck[thisPlayer][deckCounter - 6] = gardens;
    G.deck[thisPlayer][deckCounter - 7] = mine;
    G.deck[thisPlayer][deckCounter - 8] = remodel;
    G.deck[thisPlayer][deckCounter - 9] = village;
    G.deck[thisPlayer][deckCounter - 10] = baron;


    card1 = G.deck[thisPlayer][deckCounter - 1];
    card2 = G.deck[thisPlayer][deckCounter - 2];
    card3 = G.deck[thisPlayer][deckCounter - 3];
    card4 = G.deck[thisPlayer][deckCounter - 4];
    card5 = G.deck[thisPlayer][deckCounter - 5];
    card6 = G.deck[thisPlayer][deckCounter - 6];
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

    printf("Deck card: %d\n",card1);
    printf("Deck card: %d\n",card2);
    printf("Deck card: %d\n",card3);
    printf("Deck card: %d\n",card4);
    printf("Deck card: %d\n",card5);
    printf("Deck card: %d\n",card6);

    if(testG.coins != 2+G.coins){
        printf("Coin count increments by 2: FAIL\n");
    } else {
        printf("Coin count increments by 2: PASS\n");
    }

    if(testG.handCount[thisPlayer] != G.handCount[thisPlayer]){
        printf("Hand count did not change: FAIL\n");
    } else {
        printf("Hand Count did not change: PASS\n");
    }

    if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer]){
        printf("Deck count did not change: FAIL\n");
    } else {
        printf("Deck Count did not change: PASS\n");
    }





    return 0;


}
