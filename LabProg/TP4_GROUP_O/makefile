CC=gcc
CFLAGS=-std=c99 -Wpedantic -Wall -Wextra

normal: BattleShip 

BattleShip: BattleShip.c barcos.o mapas.o util.o
	$(CC) -o BattleShip.o BattleShip.c -c $(CFLAGS)
	$(CC) -o BattleShip *.o $(CFLAGS)

barcos.o: barcos.c barcos.h
	$(CC) -o barcos.o barcos.c -c $(CFLAGS)

mapas.o: mapas.c mapas.h
	$(CC) -o mapas.o mapas.c -c $(CFLAGS)

util.o: util.c util.h
	$(CC) -o util.o util.c -c $(CFLAGS)


quad: BattleShip2 

BattleShip2: BattleShip2.c barcos.o quadtree.o enemy.o player.o quadutil.o
	$(CC) -o BattleShip2.o BattleShip2.c -c $(CFLAGS)
	$(CC) -o BattleShip2 *.o $(CFLAGS)

barcos.o: barcos.c barcos.h
	$(CC) -o barcos.o barcos.c -c $(CFLAGS)

quadtree.o: quadtree.c quadtree.h
	$(CC) -o quadtree.o quadtree.c -c $(CFLAGS)

enemy.o: enemy.c enemy.h 
	$(CC) -o enemy.o enemy.c -c $(CFLAGS)

player.o: player.c player.h 
	$(CC) -o player.o player.c -c $(CFLAGS)

quadutil.o: quadutil.c quadutil.h
	$(CC) -o quadutil.o quadutil.c -c $(CFLAGS)


clean: 
	rm -f *.o BattleShip BattleShip2
