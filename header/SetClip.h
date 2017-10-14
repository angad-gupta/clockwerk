#ifndef SETCLIP_H
#define SETCLIP_H

#include "GameVariable.h"

bool load_files1()
{
	//Load the image1
	player1 = load_image("img/Player1.bmp");

	//If there was a problem in loading the image
	if (player1 == NULL)
	{
		return false;
	}

	//Load the dot image
	enemy = load_image("img/enemy.bmp");

	//If there was a problem in loading the dot
	if (enemy == NULL)
	{
		return false;
	}

	//Load the tile sheet
	tileSheet = load_image("img/Tile.bmp");

	//If there was a problem in loading the tiles
	if (tileSheet == NULL)
	{
		return false;
	}

	//Open the font
	font = TTF_OpenFont("font/quar.TTF", 20);

	//If there was an error in loading the font
	if (font == NULL)
	{
		return false;
	}

	sound = Mix_LoadWAV("sound/Player.ogg");
	if (sound == NULL) {
		printf("Unable to load WAV file: %sn", Mix_GetError());
	}

	//If everything loaded fine
	return true;
}

bool load_files2()
{
	//Load the image1
	player2 = load_image("img/Player2.bmp");

	//If there was a problem in loading the image
	if (player2 == NULL)
	{
		return false;
	}

	//Load the tile sheet
	tileSheet = load_image("img/Tile.bmp");

	//If there was a problem in loading the tiles
	if (tileSheet == NULL)
	{
		return false;
	}

	//Open the font
	font = TTF_OpenFont("font/quar.TTF", 20);

	//If there was an error in loading the font
	if (font == NULL)
	{
		return false;
	}

	sound = Mix_LoadWAV("sound/Player.ogg");
	if (sound == NULL) {
		printf("Unable to load WAV file: %sn", Mix_GetError());
	}

	//If everything loaded fine
	return true;
}

void set_clips()
{
	//Clip the sprites
	clipsDown[0].x = 0;
	clipsDown[0].y = 0;
	clipsDown[0].w = IMG_WIDTH;
	clipsDown[0].h = IMG_HEIGHT;

	clipsDown[1].x = IMG_WIDTH;
	clipsDown[1].y = 0;
	clipsDown[1].w = IMG_WIDTH;
	clipsDown[1].h = IMG_HEIGHT;

	clipsDown[2].x = IMG_WIDTH * 2;
	clipsDown[2].y = 0;
	clipsDown[2].w = IMG_WIDTH;
	clipsDown[2].h = IMG_HEIGHT;

	clipsDown[3].x = IMG_WIDTH * 3;
	clipsDown[3].y = 0;
	clipsDown[3].w = IMG_WIDTH;
	clipsDown[3].h = IMG_HEIGHT;

	clipsLeft[0].x = 0;
	clipsLeft[0].y = IMG_HEIGHT;
	clipsLeft[0].w = IMG_WIDTH;
	clipsLeft[0].h = IMG_HEIGHT;

	clipsLeft[1].x = IMG_WIDTH;
	clipsLeft[1].y = IMG_HEIGHT;
	clipsLeft[1].w = IMG_WIDTH;
	clipsLeft[1].h = IMG_HEIGHT;

	clipsLeft[2].x = IMG_WIDTH * 2;
	clipsLeft[2].y = IMG_HEIGHT;
	clipsLeft[2].w = IMG_WIDTH;
	clipsLeft[2].h = IMG_HEIGHT;

	clipsLeft[3].x = IMG_WIDTH * 3;
	clipsLeft[3].y = IMG_HEIGHT;
	clipsLeft[3].w = IMG_WIDTH;
	clipsLeft[3].h = IMG_HEIGHT;


	clipsRight[0].x = 0;
	clipsRight[0].y = IMG_HEIGHT * 2;
	clipsRight[0].w = IMG_WIDTH;
	clipsRight[0].h = IMG_HEIGHT;

	clipsRight[1].x = IMG_WIDTH;
	clipsRight[1].y = IMG_HEIGHT * 2;
	clipsRight[1].w = IMG_WIDTH;
	clipsRight[1].h = IMG_HEIGHT;

	clipsRight[2].x = IMG_WIDTH * 2;
	clipsRight[2].y = IMG_HEIGHT * 2;
	clipsRight[2].w = IMG_WIDTH;
	clipsRight[2].h = IMG_HEIGHT;

	clipsRight[3].x = IMG_WIDTH * 3;
	clipsRight[3].y = IMG_HEIGHT * 2;
	clipsRight[3].w = IMG_WIDTH;
	clipsRight[3].h = IMG_HEIGHT;

	clipsUp[0].x = 0;
	clipsUp[0].y = IMG_HEIGHT * 3;
	clipsUp[0].w = IMG_WIDTH;
	clipsUp[0].h = IMG_HEIGHT;

	clipsUp[1].x = IMG_WIDTH;
	clipsUp[1].y = IMG_HEIGHT * 3;
	clipsUp[1].w = IMG_WIDTH;
	clipsUp[1].h = IMG_HEIGHT;

	clipsUp[2].x = IMG_WIDTH * 2;
	clipsUp[2].y = IMG_HEIGHT * 3;
	clipsUp[2].w = IMG_WIDTH;
	clipsUp[2].h = IMG_HEIGHT;

	clipsUp[3].x = IMG_WIDTH * 3;
	clipsUp[3].y = IMG_HEIGHT * 3;
	clipsUp[3].w = IMG_WIDTH;
	clipsUp[3].h = IMG_HEIGHT;

}

#endif
