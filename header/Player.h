#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerAnimation.h"
#include "Button.h"

int Player()
{
	//Quit flag
	bool quit = false;

	//The stick figure
	Image1 walk1;
	Image2 walk2;
	
	//The enemy
	Enemy_Rect enemy1(653, 490, 5, 0);
	Enemy_Rect enemy2(653, 550, 8, 0);
	Enemy_Rect enemy3(653, 610, 5, 0);
	Enemy_Rect enemy4(653, 670, 8, 0);

	//The tiles that will be used
	Tile *tiles[TOTAL_TILES];

	//The frame rate regulator
	Timer fps;

	//Initialize
	if (init() == false)
	{
		return 1;
	}

	//Load the files
	if (load_files1() == false || load_files2() == false)
	{
		return 1;
	}

	//Clip the tile sheet
	clip_tiles();

	//Clip the sprite sheet
	set_clips();

	//Set the tiles
	if (set_tiles(tiles) == false)
	{
		return 1;
	}

	//Make the timer
	Timer myTimer;

	//Start the timer
	myTimer.start();
    
	//Start The Music
	channel = Mix_PlayChannel(-1, sound, -1);
	if (channel == -1) {
		printf("Unable to play WAV file: %sn", Mix_GetError());
	}
	//while (Mix_Playing(channel) != 0);

	//While the user hasn't quit
	while (quit == false)
	{
		//Start the frame timer
		fps.start();

		//While there's events to handle
		while (SDL_PollEvent(&event))
		{
			//Handle events for the Player
			walk1.handle_events1();
			walk2.handle_events2();
				
			//if esc was pressed
			if (event.key.keysym.sym == SDLK_BACKSPACE)
			{
				Mix_HaltChannel(-1);
				//Load image
				bground = SDL_LoadBMP("img/Continu.bmp");

				//Apply image to screen
				SDL_BlitSurface(bground, NULL, screen, NULL);
	
				//Update Screen
				SDL_Flip(screen);
				SDL_Delay(1000);

			}

			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				Mix_HaltChannel(-1);

				//Load image
				bground = SDL_LoadBMP("img/MenuBackground.bmp");

				//Apply image to screen
				SDL_BlitSurface(bground, NULL, screen, NULL);

				//Update Screen
				SDL_Flip(screen);

				sound1 = Mix_LoadWAV("sound/Caribbean.ogg");
				if (sound1 == NULL) {
					printf("Unable to load WAV file: %sn", Mix_GetError());
				}

				Mix_PlayChannel(-1, sound1, -1);

				return 1;
			}
			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
			{
				//Quit the program
				quit = true;
			}
		}

		//Move the Players
		walk1.move1(tiles);
		walk2.move2(tiles);

		//Move the enemy
		enemy1.emove(3, 0, tiles);
		enemy2.emove(1, 0, tiles);
		enemy3.emove(3, 0, tiles);
		enemy4.emove(2, 0, tiles);
		
		
			if (checkecoll(walk1.get_Rect(), enemy1.get_Rect())
				|| checkecoll(walk1.get_Rect(), enemy2.get_Rect())
				|| checkecoll(walk1.get_Rect(), enemy3.get_Rect())
				|| checkecoll(walk1.get_Rect(), enemy4.get_Rect()))
			{
					SDL_Rect r = walk1.get_Rect();
					r.x = 670;
					r.y = 450;
					walk1.set_Rect(r);
					walk1.show1();
				}
			if (checkecoll(walk2.get_Rect(), enemy1.get_Rect())
				|| checkecoll(walk2.get_Rect(), enemy2.get_Rect())
				|| checkecoll(walk2.get_Rect(), enemy3.get_Rect())
				|| checkecoll(walk2.get_Rect(), enemy4.get_Rect()))
			{
				SDL_Rect r = walk2.get_Rect();
				r.x = 670;
				r.y = 450;
				walk2.set_Rect(r);
				walk2.show2();
			}
			
		

		//Fill the screen white
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

		//Set the Surface
		walk1.set_Surface1();
		walk2.set_Surface2();

		//Show the tiles
		for (int t = 0; t < TOTAL_TILES; t++)
		{
			tiles[t]->show();
		}

		//Show the Player on the screen
		walk1.show1();
		walk2.show2();

		//Show the dot on the screen
		enemy1.eshow();
		enemy2.eshow();
		enemy3.eshow();
		enemy4.eshow();

		//The timer's time as a string
		std::stringstream time;

		//Convert the timer's time to a string
		time << myTimer.get_ticks() / 1000.f;

		//Render the time surface
		//seconds = TTF_RenderText_Solid(font, time.str().c_str(), textColor);

		//Apply the time surface
		//apply_surface(648 , 17, seconds, screen);

		//Free the time surface
		//SDL_FreeSurface(seconds);

		//Render the time surface
		//seconds = TTF_RenderText_Solid(font1, "sec", textColor);

		//Apply the time surface
		//apply_surface(710 , 17, seconds, screen);

		//Free the time surface
		SDL_FreeSurface(seconds);

		//Update the screen
		if (SDL_Flip(screen) == -1)
		{
			return 1;
		}

		//Cap the frame rate
		if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
		{
			SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());
		}

	}

	//Clean up
	clean_up(tiles);

	return 0;
}

#endif