#include "scoreboard.h"
#include "player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

Player* Player:: instance1 = 0;
Player* Player:: instance2 = 0;

Player* Player:: getInstance1(){
	if (!instance1){
		instance1 = new Player;
		instance1->name = "X";
		atexit(cleanup1);
	} //end if
	return instance1;
}

Player* Player:: getInstance2(){
	if (!instance2){
		instance2 = new Player;
		instance2->name = "O";
		atexit(cleanup2);
	} // end if
	return instance2;
}

void Player::cleanup1(){
	delete instance1;
}

void Player::cleanup2(){
	delete instance2;
}


Player::Player(): name(""){
	board = ScoreBoard::getInstance();
	ifstream file1;
	
}

void Player::takeInput(){
	string input;
	if (name == "X"){
		input = board->getInputX();
		if (input != "stdin"){
			file1.open (input.c_str());
		} // end if
	} else if (name == "O"){
		input = board->getInputO();
		if (input != "stdin"){
			file2.open (input.c_str());
		} // end if
	} // end if and else if
}

string Player::makeMove(){
	string move;
	if (name == "X"){
		cout << "X's move" << endl;
		if (board->getInputX() != "stdin"){
			while(!file1.eof()){
				file1 >> move;
				if (!board->isOccupied(move)) break;
			} // end while
			cout << "(plays " << move << ")" << endl;
		} else {
			cin >> move;	
		} // end if and else
	} else if (name == "O"){
		cout << "O's move" << endl;
		if (board->getInputO() != "stdin"){
			while (!file2.eof()){
				file2 >> move;
				if (!board->isOccupied(move)) break;
			} // end while
			cout << "(plays " << move << ")" << endl;
		} else {
			cin >> move;
		} // end if and else
	} // end if and else if
	return move;	
}

bool Player:: isPlayerX(){
	return name=="X";
}

bool Player:: isPlayerO(){
	return name=="O";
}
