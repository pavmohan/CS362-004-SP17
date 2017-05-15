CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testRandom: randomtestcard1.c dominion.o rngs.o
	gcc -o testRandom -g  randomtestcard1.c dominion.o rngs.o $(CFLAGS)

testRandom2: randomtestcard2.c dominion.o rngs.o
	gcc -o testRandom2 -g  randomtestcard2.c dominion.o rngs.o $(CFLAGS)

testRandom3: randomtestadventurer.c dominion.o rngs.o
	gcc -o testRandom3 -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)


badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomtestcard1.out: randomtestcard1.c dominion.o rngs.o
	echo "Results " > randomtestcard1.out
	gcc -o r1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	r1 >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	
 
randomtestcard2.out: randomtestcard2.c dominion.o rngs.o
	echo "Results " > randomtestcard2.out
	gcc -o r2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	r2 >> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out

 
randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	echo "Results " > randomtestadventurer.out
	gcc -o r3 -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	r3 >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	
	

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
