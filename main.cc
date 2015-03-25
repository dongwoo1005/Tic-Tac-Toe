#include "scoreboard.h"
#include "player.h"
#include "textdisplay.h"
#include <iostream>
#include <string>
using namespace std;

/* C++ program to administer the game of Tic-Tac-Toe
 * refer to (http://en.wikipedia.org/wiki/Tic-Tac-Toe) for detailed rules
 * Written for CS246 A3Q4b
 * Written by Dongwoo Son on March 9th 2015
 */

/* NOTES
 * Command descriptions:
 * game input1 input2 // starts the game from input1 stream and input2 stream
 *                             for player1 and player2 respectively.
 * quit // exits the program
 */

int main(){
	bool done = false;
	cout << "********************************************************" << endl;
	cout << "How To Start the Game:" << endl;
	cout << "Type Command: game sX sO" << endl;
	cout << "Where sX denotes the name of the file name for X's move." << endl;
	cout << "sX may be stdin to take input from cin." << endl;
	cout << "Similarly for O." << endl;
	cout << "E.g. game stdin stdin" << endl;
	cout << "Valid Moves are: NW N NE" << endl;
	cout << "                 W  C E" << endl;
	cout << "                 SW S SE" << endl;
	cout << "Type quit to exit the program." << endl;
	cout << "All inputs are assumed to be valid." << endl;
	cout << "It is considered invalid to claim a taken square." << endl;
	cout << "********************************************************" << endl;
	while(!done){
		string command;
		string move;
		ScoreBoard *scoreboard = ScoreBoard::getInstance();
		Player *pX = Player::getInstance1();
		Player *pO = Player::getInstance2();
		cin >> command;
		if (cin.eof()) break;
		if (command == "game") {
			scoreboard->startGame(); // reads in input1 and input2 (Reads stdin or *.txt)
			pX->takeInput();
			pO->takeInput();
			while(!scoreboard->isOver()){
				if (scoreboard->getRound()%2){ //odd-numbered round
					move = pX->makeMove();
					if (cin.fail()){done = true; break;}
					scoreboard->makeMove(pX,move);
					if(scoreboard->isOver()) break;
					move = pO->makeMove();
					if (cin.fail()){done = true; break;}
					scoreboard->makeMove(pO,move);
				} else {					   // even-numbered round
					move = pO->makeMove();
					if (cin.fail()){done = true; break;}
					scoreboard->makeMove(pO,move);
					if(scoreboard->isOver()) break;
					move = pX->makeMove();
					if (cin.fail()){done = true; break;}
					scoreboard->makeMove(pX,move);
				} // end if and else
			} // end while
			scoreboard->printScores();
		} // end if
		else if (command == "quit"){
			done = true;
		} // end else if
	} // end while
}
