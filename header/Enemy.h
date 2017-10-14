#ifndef ENEMY_H
#define ENEMY_H

#include "Screen.h"

//The Enemy
class Enemy_Rect
{
private:
	//The Enemy_Rect collision box
	SDL_Rect ebox;

	//The velocity of the Enemy_Rect
	int eVelx, eVely;

public:
	//Initializes the variables
	Enemy_Rect(int x, int y, int i, int j);

	//Moves the Enemy_Rect
	void emove(int a, int b, Tile *tiles[]);

	//Shows the Enemy_Rect on the screen
	void eshow();
	SDL_Rect get_Rect();

};


SDL_Rect Enemy_Rect::get_Rect()
{

	return ebox;
}


#endif

