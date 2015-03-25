#variables
CC=g++
CFLAGS=-c -Wall

Tic-Tac-Toe: textdisplay.o player.o scoreboard.o main.o
	$(CC) textdisplay.o player.o scoreboard.o main.o -o Tic-Tac-Toe

textdisplay.o: textdisplay.cc
	$(CC) $(CFLAGS) textdisplay.cc

player.o: player.cc
	$(CC) $(CFLAGS) player.cc

scoreboard.o: scoreboard.cc
	$(CC) $(CFLAGS) scoreboard.cc

main.o: main.cc
	$(CC) $(CFLAGS) main.cc
