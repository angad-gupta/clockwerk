#ifndef MENU_H
#define MENU_H

#include "Button.h"
#include "Creditsh.h"
#include "LoadingAnimation.h"

int Menu()
{
	int x, y;

	//Quit flag
	bool quit = false;

	//Initialize
	if (init() == false)
	{
		return 1;
	}

	//Load the files
	if (load_files_button() == false)
	{
		return 1;
	}

	Button b1 = Button(640, 300, (char*)"Start", screen);
	Button b2 = Button(640, 340, (char*)"Credits", screen);
	Button b3 = Button(640, 380, (char*)"Exit", screen);

	//Apply the images to the screen
	apply_surface(0, 0, bground, screen);


	//Update the screen
	if (SDL_Flip(screen) == -1)
	{
		return 1;
	}

	//Start The Music
	channel = Mix_PlayChannel(-1, sound, -1);
	if (channel == -1) {
		printf("Unable to play WAV file: %sn", Mix_GetError());
	}

	//While the user hasn't quit
	while (quit == false)
	{
		// message processing loop
		while (SDL_PollEvent(&event))
		{
			
			// check for messages
			switch (event.type)
			{
				// exit if the window is closed
			case SDL_QUIT:
				quit = true;
				break;
				// check for keypresses
			case SDL_KEYDOWN:
			{
								// exit if ESCAPE is pressedi
								if (event.key.keysym.sym == SDLK_ESCAPE)
									quit = true;
								break;
			}
			case SDL_MOUSEMOTION:
			{
									x = event.motion.x; y = event.motion.y;
									if (b1.onhover(x, y, 0))
									{

										b2.display(0);
										b3.display(0);
									}
									else if (b2.onhover(x, y, 0))
									{

										b1.display(0);
										b3.display(0);
									}
									else if (b3.onhover(x, y, 0))
									{

										b1.display(0);
										b2.display(0);
									}

									else
									{

										b1.display(0);
										b2.display(0);
										b3.display(0);
									}
									break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
										x = event.button.x; y = event.button.y;
										if (b1.onclick(x, y)){
											Mix_HaltChannel(-1);
											LaodingAnimation();
										}
											
										else if (b2.onclick(x, y)) Credits();
										else if (b3.onclick(x, y)){
										
											Mix_HaltChannel(-1);
											//Load image
											bground = SDL_LoadBMP("img/thankyou.bmp");

											//Apply image to screen
											SDL_BlitSurface(bground, NULL, screen, NULL);

											//Update Screen
											
											SDL_Flip(screen);
											SDL_Delay(2000);
											quit = true;
											return 0;
										}

										break;

			}
			default:
			{
					   
					   SDL_Delay(200);
					   b1.display(0);
					   b2.display(0);
					   b3.display(0);
			}
			}
		}
		SDL_Flip(screen);
	}

	//Free surfaces and font then quit SDL_ttf and SDL
	clean_up_button();

	return 0;
}

#endif