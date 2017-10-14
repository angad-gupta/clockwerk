#ifndef CREDITS_H
#define CREDITS_H

#include "Screen.h"

int Credits()
{
	//Quit flag
	bool quit = false;

	//Initialize
	if (init() == false)
	{
		return 1;
	}

	//Load image
	bground = SDL_LoadBMP("img/CreditsBackground.bmp");

	//Apply image to screen
	SDL_BlitSurface(bground, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);

	//While the user hasn't quit
	while (quit == false)
	{
		//While there's events to handle
		while (SDL_PollEvent(&event))
		{//if esc was pressed
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				//Load image
				bground = SDL_LoadBMP("img/MenuBackground.bmp");
				
				//Apply image to screen
				SDL_BlitSurface(bground, NULL, screen, NULL);
				
				//Update Screen
				SDL_Flip(screen);
				
				return 1;
			}

			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
			{
				//Quit the program
				quit = true;
			}
		}
	}

	return 0;
}

#endif