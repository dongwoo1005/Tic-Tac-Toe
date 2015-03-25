#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <string>
#include <iostream>

class TextDisplay{
	std::string theDisplay[4][3];
public:
	TextDisplay();
	void notify(std::string pos, int player);
	friend std::ostream& operator<< (std::ostream &out, const TextDisplay &td);
	
};

#endif
