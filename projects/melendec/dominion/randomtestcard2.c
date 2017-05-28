#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "great_hall"



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

    for(m=0; m<150; m++) {
    initializeGame(numPlayers, k, seed, &G);
    G.deckCount[0] = randU[q];
    q++;
    G.discardCount[0] = randU[q];
    q++;
    G.handCount[0] = randV[q];





    for(i = 0; i < G.deckCount[0]; i++){
        G.deck[0][i] = floor(Random() * treasure_map);
    }
    for(i = 0; i < G.discardCount[0]; i++){
        G.discard[0][i] = floor(Random() * treasure_map);
    }
    for(i = 0; i < G.handCount[0]; i++){
        G.hand[0][i] = floor(Random() * treasure_map);
    }

    if(G.handCount[0] == 0) {
        G.handCount[0] = 1;
    }

	// initialize a game state and player cards


	G.hand[thisPlayer][0] = great_hall;


    memcpy(&testG, &G, sizeof(struct gameState));



    playCard(handpos, choice1, choice2, choice3, &testG);


    int card[1];
    int all = 1;
    if(G.deckCount[0] +G.discardCount[0] == 0) {
        if((testG.handCount[0] != G.handCount[0]+G.deckCount[0] +G.discardCount[0])) {
            printf("Failure at empty in discard and deck test:\n");
            printf("Deck Count: %d\n",G.deckCount[0]);
            printf("Discard Count: %d\n",G.discardCount[0]);
            printf("Hand Count: %d\n",G.handCount[0]);
            all = 0;
        }
    } else {

    if(G.handCount[0] != testG.handCount[0]){
        printf("Failure at hand count test for :\n");
        printf("Deck Count: %d\n",G.deckCount[0]);
        printf("Discard Count: %d\n",G.discardCount[0]);
        printf("Hand Count: %d\n",G.handCount[0]);
        all = 0;
    } else {
        card[0] = testG.hand[0][0];
        if(G.deckCount[0]>0) {
            if(testG.hand[0][0] != G.deck[0][G.deckCount[0]-1] && testG.hand[0][testG.handCount[0]-1] != G.deck[0][G.deckCount[0]-1]) {
                printf("Failure at correct card drawn test for :\n");
                printf("Deck Count: %d\n",G.deckCount[0]);
                printf("Discard Count: %d\n",G.discardCount[0]);
                printf("Hand Count: %d\n",G.handCount[0]);
                all = 0;
            }

            if(testG.deckCount[0]+1 != G.deckCount[0]){
                printf("Failure at correct number of cards left in deck for :\n");
                printf("Deck Count: %d\n",G.deckCount[0]);
                printf("Discard Count: %d\n",G.discardCount[0]);
                printf("Hand Count: %d\n",G.handCount[0]);
                all = 0;
            }

        } else {
            int c[1];
            c[0]=0;


            for(j=0; j < G.deckCount[0]; j++){
                for(i = 0; i < 1; i++){
                    if(G.deck[0][j]==card[i]){
                        c[i] = 1;
                    }
                }
            }
            for(j=0; j < G.discardCount[0]; j++){
                for(i = 0; i < 1; i++){
                    if(G.discard[0][j]==card[i]){
                        c[i] = 1;
                    }
                }
            }
            if(!(c[0])){
                printf("Failure at correct cards drawn for empty deck test for :\n");
                printf("Deck Count: %d\n",G.deckCount[0]);
                printf("Discard Count: %d\n",G.discardCount[0]);
                printf("Hand Count: %d\n",G.handCount[0]);
                all = 0;
            }



        }

    }
    }

    if (testG.numActions!=1) {
        printf("Failure at increase action step :\n");
        printf("Deck Count: %d\n",G.deckCount[0]);
        printf("Discard Count: %d\n",G.discardCount[0]);
        printf("Hand Count: %d\n",G.handCount[0]);
        all = 0;
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
