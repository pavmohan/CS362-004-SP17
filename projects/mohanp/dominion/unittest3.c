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

    printf("Unit test for supply count method");
    int curseCount= G.supplyCount[curse];

    if(supplyCount(curse,&G) == 10 ) {
        printf("Correct number of curse cards reported: PASS\n");
    } else {
        printf("Correct number of curse cards reported: FAIL\n");
    }

     if(curseCount==G.supplyCount[curse] ) {
        printf("Number of curse cards not altered: PASS\n");
    } else {
        printf("Number of curse cards not altered: FAIL\n");
    }
if(k[0]==adventurer && k[1] == embargo && k[2]== village && k[3]== remodel &&
       k[4]== mine && k[5] == cutpurse && k[6] == sea_hag && k[7] == tribute &&
       k[8] == smithy && k[9] == council_room) {
            printf("No state change in kingdom: PASS\n");
       } else {
            printf("No state change in kingdom: FAIL\n");
       }
    return 0;
}
