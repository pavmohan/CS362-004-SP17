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
    int situation = -1;
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    srand(seed);
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, remodel, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    SelectStream(2);
    PutSeed(3);

    for(m=0; m<200; m++) {
    initializeGame(numPlayers, k, seed, &G);
    G.deckCount[0] = floor(Random() * 20);
    G.discardCount[0] = floor(Random() * 20);
    G.handCount[0] = floor(Random() * 10);

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
    if(m == 15) {
        G.deckCount[0] = 0;
    } else if(m==16){
        G.deckCount[0] = 0;
        G.discardCount[0] = 0;
    }
	// initialize a game state and player cards


	G.hand[thisPlayer][0] = smithy;


    memcpy(&testG, &G, sizeof(struct gameState));




    playCard(handpos, choice1, choice2, choice3, &testG);



    int card[3];
    int all = 1;
    if(G.deckCount[0] +G.discardCount[0] < 3) {
        if((testG.handCount[0] != G.handCount[0]+G.deckCount[0] +G.discardCount[0])) {
            printf("Failure at fewer than 3 in discard and low deck test:\n");
            printf("Deck Count: %d\n",G.deckCount[0]);
            printf("Discard Count: %d\n",G.discardCount[0]);
            printf("Hand Count: %d\n",G.handCount[0]);
            all = 0;
        }
    } else {

    if(G.handCount[0]+2 != testG.handCount[0]){
        printf("Failure at hand count test for :\n");
        printf("Deck Count: %d\n",G.deckCount[0]);
        printf("Discard Count: %d\n",G.discardCount[0]);
        printf("Hand Count: %d\n",G.handCount[0]);
        all = 0;
    } else {
        card[0] = testG.hand[0][0];
        card[1] = testG.hand[0][G.handCount[0]];
        card[2] = testG.hand[0][G.handCount[0]+1];
        if(G.deckCount[0]>2) {
            if(testG.hand[0][0] != G.deck[0][G.deckCount[0]-1] || testG.hand[0][0] != G.deck[0][G.deckCount[0]-2] || testG.hand[0][0] != G.deck[0][G.deckCount[0]-3]) {
                printf("Failure at correct card drawn test for :\n");
                printf("Deck Count: %d\n",G.deckCount[0]);
                printf("Discard Count: %d\n",G.discardCount[0]);
                printf("Hand Count: %d\n",G.handCount[0]);
                all = 0;
            }
            if(testG.hand[0][testG.handCount[0]-1]  != G.deck[0][G.deckCount[0]-1] || testG.hand[0][testG.handCount[0]-1] != G.deck[0][G.deckCount[0]-2] || testG.hand[0][testG.handCount[0]-1] != G.deck[0][G.deckCount[0]-3]) {
                printf("Failure at correct card at third drawn test for :\n");
                printf("Deck Count: %d\n",G.deckCount[0]);
                printf("Discard Count: %d\n",G.discardCount[0]);
                printf("Hand Count: %d\n",G.handCount[0]);
                all = 0;
            }
            if(testG.hand[0][testG.handCount[0]-2]  != G.deck[0][G.deckCount[0]-1] || testG.hand[0][testG.handCount[0]-2] != G.deck[0][G.deckCount[0]-2] || testG.hand[0][testG.handCount[0]-2] != G.deck[0][G.deckCount[0]-3]) {
                printf("Failure at correct card at second drawn test for :\n");
                printf("Deck Count: %d\n",G.deckCount[0]);
                printf("Discard Count: %d\n",G.discardCount[0]);
                printf("Hand Count: %d\n",G.handCount[0]);
                all = 0;
            }
            if(testG.deckCount[0]+3 != G.deckCount[0]){
                printf("Failure at correct number of cards left in deck for :\n");
                printf("Deck Count: %d\n",G.deckCount[0]);
                printf("Discard Count: %d\n",G.discardCount[0]);
                printf("Hand Count: %d\n",G.handCount[0]);
                all = 0;
            }

        } else {
            int c[3];
            c[0]=0;
            c[1]=0;
            c[2]=0;

            for(j=0; j < G.deckCount[0]; j++){
                for(i = 0; i < 3; i++){
                    if(G.deck[0][j]==card[i]){
                        c[i] = 1;
                    }
                }
            }
            for(j=0; j < G.discardCount[0]; j++){
                for(i = 0; i < 3; i++){
                    if(G.discard[0][j]==card[i]){
                        c[i] = 1;
                    }
                }
            }
            if(!(c[0]&&c[1]&&c[2])){
                printf("Failure at correct cards drawn for >3 in deck test for :\n");
                printf("Deck Count: %d\n",G.deckCount[0]);
                printf("Discard Count: %d\n",G.discardCount[0]);
                printf("Hand Count: %d\n",G.handCount[0]);
                all = 0;
            }



        }

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
