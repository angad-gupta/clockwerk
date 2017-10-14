#ifndef BUTTON_H
#define BUTTON_H

#include "Screen.h"

class Button{
public:
	Button(){}
	Button(int, int, char*, SDL_Surface*);
	void load_all(int);
	void display(int);
	bool onhover(int, int, int);
	bool onclick(int, int);
private:
	char *name;
	SDL_Rect button;
	SDL_Color black, green;
	SDL_Surface* txt, *onpress, *menu;

};

Button::Button(int x, int y, char *c, SDL_Surface* s)
{
	name = new char[50];
	button.x = x; button.y = y;
	name = c;
	screen = s;
	load_all(0);
	display(0);
}

void Button::load_all(int id)
{
	black = { 0, 0, 0 };
	font1 = TTF_OpenFont("font/TFPironv2-stencil.otf", 25);
	if (id == 0){
		font2 = TTF_OpenFont("font/TFPironv2-stencil.otf", 30);
		green = { 0, 255, 0 };
		txt = TTF_RenderText_Solid(font1, name, black);
		onpress = TTF_RenderText_Solid(font2, name, green);
		button.w = txt->w;
		button.h = txt->h;
	}

}

void Button::display(int id)
{
	SDL_FillRect(screen, &button, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0x99));
	if (id == 0) {
		SDL_BlitSurface(menu, 0, screen, 0);
		SDL_BlitSurface(txt, 0, screen, &button);
	}

}

bool Button::onhover(int x, int y, int id)
{
	SDL_FillRect(screen, &button, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0x99));
	if (x >= button.x && x <= button.x + button.w && y >= button.y && y <= button.y + button.h)
	{
		if (id == 0) SDL_BlitSurface(onpress, 0, screen, &button);

		return true;
	}
	if (id == 0) SDL_BlitSurface(txt, 0, screen, &button);

	return false;
}

bool Button::onclick(int x, int y)
{
	if (x >= button.x && x <= button.x + button.w && y >= button.y && y <= button.y + button.h)
		return true;
	return false;
}



bool load_files_button()
{
	//Load the background image
	bground = load_image("img/MenuBackground.bmp");

	//Open the font
	font = TTF_OpenFont("font/TFPironv2-stencil.otf", 28);

	//If there was a problem in loading the background
	if (bground == NULL)
	{
		return false;
	}

	//If there was an error in loading the font
	if (font == NULL)
	{
		return false;
	}

	sound = Mix_LoadWAV("sound/Caribbean.ogg");
	if (sound == NULL) {
		printf("Unable to load WAV file: %sn", Mix_GetError());
	}

	//If everything loaded fine
	return true;
}

void clean_up_button()
{
	//Free the surfaces
	SDL_FreeSurface(bground);

	//Close the font that was used
	TTF_CloseFont(font);

	//Quit SDL_ttf
	TTF_Quit();

	//Quit SDL
	SDL_Quit();
}

#endif