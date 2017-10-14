#ifndef STARTUP_H
#define STARTUP_H

#include "Header.h"

int StartUp()
{
	//Initialize
	if (init() == false)
	{
		return 1;
	}

	//Load image
	bground = SDL_LoadBMP("img/c.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(300);

	//Load image
	bground = SDL_LoadBMP("img/l.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(300);

	//Load image
	bground = SDL_LoadBMP("img/o.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(300);

	//Load image
	bground = SDL_LoadBMP("img/c_c.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(300);

	//Load image
	bground = SDL_LoadBMP("img/k.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(300);

	//Load image
	bground = SDL_LoadBMP("img/w.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(300);

	//Load image
	bground = SDL_LoadBMP("img/e.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(300);

	//Load image
	bground = SDL_LoadBMP("img/r.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(300);

	//Load image
	bground = SDL_LoadBMP("img/k_k.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);
	SDL_Delay(500);

	//Open the menu
	Menu();

	return 0;
}

#endif