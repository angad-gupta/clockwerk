#ifndef LOADINGANIMATION_H
#define LOADINGANIMATION_H

#include "Screen.h"

int LaodingAnimation()
{
	//Load image
	bground = SDL_LoadBMP("img/loading_1.png");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(500);

	//Load image
	bground = SDL_LoadBMP("img/loading_2.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(500);

	//Load image
	bground = SDL_LoadBMP("img/loading_3.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(500);

	//Load image
	bground = SDL_LoadBMP("img/loading_4.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(500);

	//Load image
	bground = SDL_LoadBMP("img/loading_5.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);
	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(500);

	
	Player();
	return 0;
}
#endif