#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

# include "Header.h"

//The tile
class Tile
{
private:
	//The attributes of the tile
	SDL_Rect box;

	//The tile type
	int type;

public:
	//Initializes the variables
	Tile(int x, int y, int tileType);

	//Shows the tile
	void show();

	//Get the tile type
	int get_type();

	//Get the collision box
	SDL_Rect get_box();
};

//Image1
class Image1
{
private:
	//The collision box of the square
	SDL_Rect box;

	//The offset
	int xMove1, yMove1;

	//Its rate of movement
	int xVel1, yVel1;

	//Its current frame
	int frame1;

	//Its animation status
	int status1;

public:
	//Initializes the variables
	Image1();

	//Handles input
	void handle_events1();

	//Moves the Image1
	void move1(Tile *tiles[]);

	//Shows the stick figure
	void show1();

	//Sets the Surface over the Image1
	void set_Surface1();
	SDL_Rect get_Rect();
	void set_Rect(SDL_Rect);
};

void Image1::set_Rect(SDL_Rect r)
{
	

	xMove1 = r.x;
	yMove1 = r.y;
}
SDL_Rect Image1::get_Rect()
{

	return box;
}

//Image2
class Image2
{
private:
	//The collision box of the square
	SDL_Rect box;

	//The offset
	int xMove2, yMove2;

	//Its rate of movement
	int xVel2, yVel2;

	//Its current frame
	int frame2;

	//Its animation status
	int status2;

public:
	//Initializes the variables
	Image2();

	//Handles input
	void handle_events2();

	//Moves the Image2
	void move2(Tile *tiles[]);

	//Shows the stick figure
	void show2();

	//Sets the Surface over the Image2
	void set_Surface2();
	SDL_Rect get_Rect();
	void set_Rect(SDL_Rect);
};

void Image2::set_Rect(SDL_Rect r)
{


	xMove2 = r.x;
	yMove2 = r.y;
}
SDL_Rect Image2::get_Rect()
{

	return box;
}

//The timer
class Timer
{
private:
	//The clock time when the timer started
	int startTicks;

	//The ticks stored when the timer was paused
	int pausedTicks;

	//The timer status
	bool paused;
	bool started;

public:
	//Initializes variables
	Timer();

	//The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	//Gets the timer's time
	int get_ticks();

	//Checks the status of the timer
	bool is_started();
	bool is_paused();
};

#endif