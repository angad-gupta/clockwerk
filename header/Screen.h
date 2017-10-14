#ifndef SCREEN_H
#define SCREEN_H

#include "Header.h"

bool init()
{
	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	//Set up the screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_FULLSCREEN);

	//sCheck if there's any joysticks
	if (SDL_NumJoysticks() < 0)
	{
		return false;
	}

	//Open the joystick
	stick1 = SDL_JoystickOpen(0);
	stick2 = SDL_JoystickOpen(1);
	
	/*
	//If there's a problem opening the joystick
	if (stick1 == NULL || stick2 == NULL)
	{
		return false;
	}
	*/

	//If there was an error in setting up the screen
	if (screen == NULL)
	{
		return false;
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		return false;
	}

	if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		printf("Unable to initialize audio: %sn", Mix_GetError());
		exit(1);
	}

	//Set the window caption
	SDL_WM_SetCaption("Clock-Werk", NULL);

	//If everything initialized fine
	return true;
}

#endif