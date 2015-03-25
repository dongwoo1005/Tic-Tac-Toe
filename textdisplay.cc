#include "textdisplay.h"
#include <string>
using namespace std;

TextDisplay::TextDisplay(){
	for (int r=0; r<4; ++r){
		for (int c=0; c<3; ++c){
			if (r==0){
				theDisplay[r][c] = " _";
			}
			else {
				if (c==2){
					theDisplay[r][c] = "|_|";
				} else {
					theDisplay[r][c] = "|_";
				}
			}
		}
	}	
}

void TextDisplay::notify(string pos, int player){
	char playerc = '_';
	if (player == 1) {playerc = 'X';} // X
	else if (player == 2) {playerc = 'O';} // O
	if (pos == "NW"){theDisplay[1][0][1]=playerc;}
	else if (pos == "N"){theDisplay[1][1][1]=playerc;}
	else if (pos == "NE"){theDisplay[1][2][1]=playerc;}
	else if (pos == "W"){theDisplay[2][0][1]=playerc;}
	else if (pos == "C"){theDisplay[2][1][1]=playerc;}
	else if (pos == "E"){theDisplay[2][2][1]=playerc;}
	else if (pos == "SW"){theDisplay[3][0][1]=playerc;}
	else if (pos == "S"){theDisplay[3][1][1]=playerc;}
	else if (pos == "SE"){theDisplay[3][2][1]=playerc;}	
}

ostream& operator<<(ostream &out, const TextDisplay &td){
	for (int r=0; r<4; ++r){
		for (int c=0; c<3; ++c){
			out << td.theDisplay[r][c];
		}
		out << endl;
	}
	return out;
}
