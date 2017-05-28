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
    int situation = -1;
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 989;
    srand(seed);
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, remodel, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    SelectStream(2);
    PutSeed(3);
    int w = 0;
    int randU[150];
    int randV[150];
    for(w=0; w < 100; w++){
        randU[w] = floor(Random() * 20);
        randV[w] = floor(Random() * 10);
    }
    int q = 0;


    for(m=0; m<5; m++) {
    int treasureCount = 0;
    int treasureHand = 0;
    int finalHand = 0;
    initializeGame(numPlayers, k, seed, &G);
    G.deckCount[0] = randU[q];
    q++;
    G.discardCount[0] = randU[q];
    q++;
    G.handCount[0] = randV[q];





    for(i = 0; i < G.deckCount[0]; i++){
        G.deck[0][i] = floor(Random() * treasure_map);
        if(G.deck[0][i]==copper || G.deck[0][i]==silver || G.deck[0][i]==gold) {
            treasureCount++;
        }
    }
    for(i = 0; i < G.discardCount[0]; i++){
        G.discard[0][i] = floor(Random() * treasure_map);
    }
    for(i = 0; i < G.handCount[0]; i++){
        G.hand[0][i] = floor(Random() * treasure_map);
        if(G.hand[0][i]==copper || G.hand[0][i]==silver || G.hand[0][i]==gold) {
            treasureHand++;
        }
    }

    if(G.handCount[0] == 0) {
        G.handCount[0] = 1;
    }

	// initialize a game state and player cards


	G.hand[thisPlayer][0] = adventurer;


    memcpy(&testG, &G, sizeof(struct gameState));



    playCard(handpos, choice1, choice2, choice3, &testG);



    int card[1];
    int all = 1;
    for(i = 0; i < testG.handCount[0]; i++) {
        if(testG.hand[0][i]==copper || testG.hand[0][i]==silver || testG.hand[0][i]==gold) {
            finalHand++;
        }
    }


    if(treasureCount >= 2) {
        if(treasureHand + 2 != finalHand){
            printf("Failure at 2 treasure cards in deck not added to hand :\n");
            printf("Deck Count: %d\n",G.deckCount[0]);
            printf("Discard Count: %d\n",G.discardCount[0]);
            printf("Hand Count: %d\n",G.handCount[0]);
            all = 0;
        }
    } else if(treasureCount == 1) {
        if(treasureHand + 1 != finalHand){
            printf("Failure at 1 treasure cards in deck not added to hand :\n");
            printf("Deck Count: %d\n",G.deckCount[0]);
            printf("Discard Count: %d\n",G.discardCount[0]);
            printf("Hand Count: %d\n",G.handCount[0]);
            all = 0;
        }

    } else {
        if(treasureHand + 1 != finalHand){
            printf("Failure at no treasure cards in deck :\n");
            printf("Deck Count: %d\n",G.deckCount[0]);
            printf("Discard Count: %d\n",G.discardCount[0]);
            printf("Hand Count: %d\n",G.handCount[0]);
            all = 0;
        }

    }



    //No state change for kingdom and victory card piles
    if(k[0]==adventurer && k[1] == embargo && k[2]== village && k[3]== remodel &&
       k[4]== mine && k[5] == cutpurse && k[6] == sea_hag && k[7] == tribute &&
       k[8] == smithy && k[9] == council_room) {

       } else {
            printf("Failure at kingdom card unchanged test\n");
            printf("Deck Count: %d\n",G.deckCount[0]);
            printf("Discard Count: %d\n",G.discardCount[0]);
            printf("Hand Count: %d\n",G.handCount[0]);
            all = 0;
       }
    if(G.supplyCount[thisPlayer] == testG.supplyCount[thisPlayer]) {

    } else {
            printf("Failure at supply card unchanged test\n");
            printf("Deck Count: %d\n",G.deckCount[0]);
            printf("Discard Count: %d\n",G.discardCount[0]);
            printf("Hand Count: %d\n",G.handCount[0]);
            all = 0;
    }
    if(all) {
        printf("All tests PASSED\n");

    }

    }
    return 0;


}
