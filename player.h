#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "scoreboard.h"
#include <string>
#include <fstream>

class ScoreBoard;	// Forward declaration

class Player{
		std::string name;	// to save the name of the player
		ScoreBoard* board;	// pointer to the board

		std::ifstream file1, file2;	// to keep track of the filestream

		static Player *instance1;	// first player
		static Player *instance2;	// second player

		/* cleanup1()	and	  cleanup2()
  		 * Purpose: to delete the created object by getInstance() at the program termination
		 * Returns: None
	 	 */
		static void cleanup1();
		static void cleanup2();

		Player();	

	public:
		/* getInstance1()	and	   getInstance2()
		 * Purpose: to ensure that there are only two Player objects created
		 * 			creates a Player object if it was never called
		 * Returns: a pointer to the Player created or previously created 
	 	 */
		static Player* getInstance1();
		static Player* getInstance2();

		/* makeMove()
		 * Purpose: to fetch the next move from cin or from the file stream according to the 
		 *			input value saved in the board.
		 * Returns: the fetched move in a string (one of C,N,E,W,S,NW,NE,SW,SE)
		 */
		std::string makeMove();
		
		/* takeInput()
		 * Purpose: takes the name of the Player and following input registered in the board
		 *			If the input is a file, it opens the file.
		 * Returns: None
		 */
		void takeInput();

		/* isPlayerX()  and   isPlayerO()
		 * Purpose: to look up the Player's name and check if the 
		 *  		name is either X or O.
		 * Returns: True if Player's name is either X for isPlayerX() or O for isPlayerO()
		 * 			False otherwise
	     */ 
		bool isPlayerX();
		bool isPlayerO();
};




#endif
