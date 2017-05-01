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

    int i, j, m,n;
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
	G.hand[thisPlayer][0] = smithy;
    G.hand[thisPlayer][1] = estate;
    G.hand[thisPlayer][2] = duchy;
    G.hand[thisPlayer][3] = province;
    G.hand[thisPlayer][4] = copper;
	printf("Testing discard method\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	int target = -1;
	for(j=0; j <2; j++) {
        for(i = 0; i < 5; i++) {
            for(m = 0; m < 2; m++) {
                memcpy(&testG, &G, sizeof(struct gameState));
                target=testG.hand[j][i];
                printf("Testing trash flag set to %d from pos %d of player %d\n",m,i,j);
                discardCard(i,j,&testG,m);
                if(testG.hand[j][i] == -1) {
                    printf("Target card discarded from right position in hand: PASS\n");
                }else{
                    printf("Target card discarded from right position in hand: FAIL\n");
                }
                if(testG.handCount[j]+1 == G.handCount[j]) {
                        printf("Hand Count decremented by exactly 1: PASS\n");
                } else {
                        printf("Hand Count decremented by exactly 1: FAIL\n");
                }
                if(m == 0) {
                    if(testG.playedCards[testG.playedCardCount-1]==target) {
                        printf("If card not trashed, added to played pile: PASS\n");
                    } else {
                        printf("If card not trashed, added to played pile: FAIL\n");
                    }
                    if(testG.playedCardCount==G.playedCardCount+1) {
                        printf("If card not trashed, played pile incremented: PASS\n");
                    } else {
                        printf("If card not trashed, played pile incremented: FAIL\n");
                    }
                }
                int c1 = 1;
                for(n = 0; n < 5; n++) {
                    if(n!=i){
                       if (testG.hand[j][n] != G.hand[j][n]) {
                            c1=0;
                       }
                    }
                }
                if(c1) {
                        printf("Remaining cards in hand unaffected: PASS\n");
                } else {
                        printf("Remaining cards in hand unaffected: FAIL\n");
                }

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


            }
        }
	}


    return 0;


}
