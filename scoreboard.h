#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__
#include <string>
#include <iostream>
#include "player.h"
#include "textdisplay.h"

class Player;	// Forward declaration
class TextDisplay;

class ScoreBoard{
		int scoreX, scoreO;		// to count the scores
		std::string inputX, inputO; // to save the inputs (stdin or *.txt)
		int NW, N, NE, W, C, E, SW, S, SE; // to track the game board
		int round; // to count how many game was called
		TextDisplay *td;
		static ScoreBoard *instance;	// THE board
		ScoreBoard();	// ctor
		/* cleanup()
		 * Purpose: to delete the created object by getInstance() at the program termination
		 * Returns: None
		 */
		static void cleanup();
		
	public:
		/* getInstance()
		 * Purpose: to ensure that only one ScoreBoard object is created
		 *			creates a ScoreBoard if it was never called.
		 * Returns: pointer to the ScoreBoard created or previously created.
		 */
		static ScoreBoard *getInstance();

		/* printScores()
		 * Purpose: to print out the current scores in the scoreboard
		 *			in the format of
		 *			Score is
		 *			X scoreX
		 *			O scoreO
		 * Returns: None
		 */
		void printScores();

		/* makeMove(p, move)
		 * Purpose: to register the move to the scoreboard of the Player p
		 * Returns: None
		 */
		void makeMove(Player* p, std::string move);

		/* startGame()
		 * Purpose: to restart the game
		 * 			it resets the board move values to 0, count the round up, 
		 *			and receives new input from cin 
		 * Returns: None
		 */
		void startGame();

		/* isOver()
		 * Purpose: to determine if the game is over according to the rule
		 *			and print out which player has won the game
		 * Returns: true if the game is over
		 * 			false otherwise
		 */
		bool isOver();

		/* isOccupied(move)
		 * Purpose: to determine if the move is already occupied in the board
		 * Returns: true if it is occupied
		 * 			false otherwise
		 */
		bool isOccupied(std::string move);

		/* getInputX()	and	   getInputO()
		 * Purpose: to return the value of inputX or inputO in the board
		 * Returns: the string value of inputX or inputO according to the functions called
		 */
		std::string getInputX();
		std::string getInputO();

		/* getRound()
		 * Purpose: to return the value of round in the board
		 * Returns: current round in integer
		 */
		int getRound();
};

#endif
