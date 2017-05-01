#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main()
{
printf("Testing get cost method\n");
if (getCost(curse)==0){
    printf("Curse: PASS");
} else {
    printf("Curse: FAIL");
}
printf("\n");
if (getCost(estate)==2){
    printf("estate: PASS");
} else {
    printf("estate: FAIL");
}
printf("\n");
if (getCost(province)==8){
    printf("province: PASS");
} else {
    printf("province: FAIL");
}
printf("\n");
if (getCost(copper)==0){
    printf("copper: PASS");
} else {
    printf("copper: FAIL");
}
printf("\n");
if (getCost(silver)==3){
    printf("silver: PASS");
} else {
    printf("silver: FAIL");
}
printf("\n");
if (getCost(gold)==6){
    printf("gold: PASS");
} else {
    printf("gold: FAIL");
}
printf("\n");
if (getCost(adventurer)==6){
    printf("adventurer: PASS");
} else {
    printf("adventurer: FAIL");
}
printf("\n");
if (getCost(council_room)==5){
    printf("council_room: PASS");
} else {
    printf("council_room: FAIL");
}
printf("\n");
if (getCost(feast)==4){
    printf("feast: PASS");
} else {
    printf("feast: FAIL");
}
printf("\n");
if (getCost(gardens)==4){
    printf("gardens: PASS");
} else {
    printf("gardens: FAIL");
}
printf("\n");
if (getCost(mine)==5){
    printf("mine: PASS");
} else {
    printf("mine: FAIL");
}
printf("\n");
if (getCost(remodel)==4){
    printf("remodel: PASS");
} else {
    printf("remodel: FAIL");
}
printf("\n");
if (getCost(smithy)==4){
    printf("smithy: PASS");
} else {
    printf("smithy: FAIL");
}
printf("\n");
if (getCost(village)==3){
    printf("village: PASS");
} else {
    printf("village: FAIL");
}
printf("\n");
if (getCost(baron)==4){
    printf("baron: PASS");
} else {
    printf("baron: FAIL");
}
printf("\n");
if (getCost(great_hall)==3){
    printf("great_hall: PASS");
} else {
    printf("great_hall: FAIL");
}
printf("\n");
if (getCost(village)==3){
    printf("village: PASS");
} else {
    printf("village: FAIL");
}
printf("\n");
if (getCost(minion)==5){
    printf("minion: PASS");
} else {
    printf("minion: FAIL");
}
printf("\n");

if (getCost(steward)==3){
    printf("steward: PASS");
} else {
    printf("steward: FAIL");
}printf("\n");
if (getCost(tribute)==5){
    printf("tribute: PASS");
} else {
    printf("tribute: FAIL");
}printf("\n");
if (getCost(ambassador)==3){
    printf("ambassador: PASS");
} else {
    printf("ambassador: FAIL");
}
printf("\n");
if (getCost(cutpurse)==4){
    printf("cutpurse: PASS");
} else {
    printf("cutpurse: FAIL");
}
printf("\n");
if (getCost(embargo)==2){
    printf("embargo: PASS");
} else {
    printf("embargo: FAIL");
}
printf("\n");
if (getCost(outpost)==5){
    printf("outpost: PASS");
} else {
    printf("outpost: FAIL");
}
printf("\n");
if (getCost(salvager)==4){
    printf("salvager: PASS");
} else {
    printf("salvager: FAIL");
}
printf("\n");
if (getCost(sea_hag)==4){
    printf("sea_hag: PASS");
} else {
    printf("sea_hag: FAIL");
}
printf("\n");
if (getCost(treasure_map)==4){
    printf("treasure_map: PASS");
} else {
    printf("treasure_map: FAIL");
}

printf("\n");
return 0;
}
