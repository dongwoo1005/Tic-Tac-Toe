#include "scoreboard.h"
#include "player.h"
#include "textdisplay.h"
#include <iostream>
#include <cstdlib>
using namespace std;

ScoreBoard* ScoreBoard::instance = 0;

ScoreBoard* ScoreBoard::getInstance(){
	if (!instance){
		instance = new ScoreBoard;
		atexit(cleanup);
	} // end if
	return instance;
}

ScoreBoard::ScoreBoard(): scoreX(0), scoreO(0), inputX(""), inputO(""),
	NW(0), N(0), NE(0), W(0), C(0), E(0), SW(0), S(0), SE(0), round(0) {
	td = new TextDisplay;
}

void ScoreBoard::printScores(){
	cout << "Score is" << endl;
	cout << "X " << scoreX << endl;
	cout << "O " << scoreO << endl;
}

void ScoreBoard::cleanup() {
	delete instance;
}


void ScoreBoard::startGame(){
	cin >> inputX;
	cin >> inputO;	
	NW=N=NE=W=C=E=SW=S=SE=0;
	round++;
	delete td;
	td = new TextDisplay;
	cout << *td;
}

void ScoreBoard::makeMove(Player* p, string move){
	int marker = 0;
	if (p->isPlayerX()) { marker=1; }
	else if (p->isPlayerO()) { marker=2; }
	if (move == "NW" && !NW) { NW = marker; }
	else if (move == "N" && !N) { N = marker; }
	else if (move == "NE" && !NE) { NE = marker; }
	else if (move == "W" && !W) { W = marker; }
	else if (move == "C" && !C) { C = marker; }
	else if (move == "E" && !E) { E = marker; }
	else if (move == "SW" && !SW) { SW = marker; }
	else if (move == "S" && !S) { S = marker; }
	else if (move == "SE" && !SE) { SE = marker; }
	td->notify(move,marker);
	cout << *td;
}

bool ScoreBoard::isOver(){
	bool over=false;
	int winner=0;
	if (((NW==N)&&(N==NE))&&(N!=0)){ over=true; winner=N; }
	else if (((W==C)&&(C==E))&&(C!=0)) { over=true; winner=C; }
	else if (((SW==S)&&(S==SE))&&(S!=0)) { over=true; winner=S; }
	else if (((NW==W)&&(W==SW))&&(W!=0)) { over=true; winner=W; }
	else if (((N==C)&&(C==S))&&(C!=0)) {over=true; winner=C; }
	else if (((NE==E)&&(E==SE))&&(E!=0)) {over=true; winner=E;}
	else if (((NW==C)&&(C==SE))&&(C!=0)) {over=true; winner=C;}
	else if (((NE==C)&&(C==SW))&&(C!=0)) {over=true; winner=C;}
	else if (((((NW!=0)&&(N!=0))&&((NE!=0)&&(W!=0)))
	&&(((C!=0)&&(E!=0))&&((SW!=0)&&(S!=0))))&&(SE!=0)){
		over=true;
	}
	if (over){
		if (winner==0) {
			cout << "Draw" << endl;
		} // end if
		if (winner==1) {
			cout << "X wins" << endl;
			scoreX++;
		} // end if
		if (winner==2) {
			cout << "O wins" << endl;
			scoreO++;
		} // end if
		return true;
	} else {
		return false;
	} // end if and else
}

bool ScoreBoard::isOccupied(string move){
	if (move == "NW"){ return NW ? true: false; }
	else if (move == "N") { return N ? true: false; }
	else if (move == "NE") { return NE ? true: false; }
	else if (move == "W") { return W ? true: false; }
	else if (move == "C") { return C ? true: false; }
	else if (move == "E") { return E ? true: false; }
	else if (move == "SW") { return SW ? true: false; }
	else if (move == "S") { return S ? true: false; }
	else if (move == "SE") { return SE ? true: false; }
	return false;
}

string ScoreBoard::getInputX(){
	return inputX;
}

string ScoreBoard::getInputO(){
	return inputO;
}

int ScoreBoard::getRound(){
	return round;
}
