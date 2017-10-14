#ifndef PLAYERANIMATION_H
#define PLAYERANIMATION_H

#include "screen.h"
#include <fstream>
#include "PlayerClass.h"
#include "Collision.h"
#include "Map.h"
#include "SetClip.h"
#include "Enemy.h"
#include "Header.h"


bool checkecoll(SDL_Rect A,SDL_Rect B)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	//Calculate the sides of rect B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

}

void clean_up(Tile *tiles[])
{
	//Free the surfaces
	SDL_FreeSurface(player1);
	SDL_FreeSurface(player2);
	SDL_FreeSurface(enemy);
	SDL_FreeSurface(tileSheet);

	//Free the tiles
	for (int t = 0; t < TOTAL_TILES; t++)
	{
		delete tiles[t];
	}

	//Close the font
	TTF_CloseFont(font);

	//Quit SDL_ttf
	TTF_Quit();

	//Free the music
	Mix_FreeChunk(sound);

	//Quit Mixer
	Mix_CloseAudio();

	//Quit SDL
	SDL_Quit();
}

bool touches_wall(SDL_Rect box, Tile *tiles[])
{
	//Go through the tiles
	for (int t = 0; t < TOTAL_TILES; t++)
	{
		
		if ((tiles[t]->get_type() >= TILE_DOOR_OPEN_LEFT_01) && (tiles[t]->get_type() <= TILE_DOOR_OPEN_LEFT_01)
			|| (tiles[t]->get_type() >= TILE_BLOCK) && (tiles[t]->get_type() <= TILE_BLOCK)
			|| (tiles[t]->get_type() >= TILE_DOOR_OPEN_LEFT_04) && (tiles[t]->get_type() <= TILE_DOOR_OPEN_LEFT_04)
			|| (tiles[t]->get_type() >= TILE_DOOR_OPEN_RIGHT_01) && (tiles[t]->get_type() <= TILE_DOOR_OPEN_RIGHT_01)
			|| (tiles[t]->get_type() >= TILE_DOOR_OPEN_RIGHT_04) && (tiles[t]->get_type() <= TILE_DOOR_OPEN_RIGHT_04)
			|| (tiles[t]->get_type() >= TILE_COCONUT_00) && (tiles[t]->get_type() <= TILE_COCONUT_00)
			|| (tiles[t]->get_type() >= TILE_COCONUT_01) && (tiles[t]->get_type() <= TILE_COCONUT_01)
			|| (tiles[t]->get_type() >= TILE_COCONUT_10) && (tiles[t]->get_type() <= TILE_COCONUT_10)
			|| (tiles[t]->get_type() >= TILE_COCONUT_11) && (tiles[t]->get_type() <= TILE_COCONUT_11)
			|| (tiles[t]->get_type() >= TILE_ENEMY) && (tiles[t]->get_type() <= TILE_ENEMY))
		{
			//If the collision box touches the water tile
			if (check_collision(box, tiles[t]->get_box()) == true)
			{
				//Quit SDL
				//SDL_Quit();
				return true;
			}
		}
		if ((tiles[t]->get_type() >= TILE_TREASURE_T1) && (tiles[t]->get_type() <= TILE_TREASURE_T1)
			|| (tiles[t]->get_type() >= TILE_TREASURE_T2) && (tiles[t]->get_type() <= TILE_TREASURE_T2)
			|| (tiles[t]->get_type() >= TILE_TREASURE_T3) && (tiles[t]->get_type() <= TILE_TREASURE_T3)
			|| (tiles[t]->get_type() >= TILE_TREASURE_T4) && (tiles[t]->get_type() <= TILE_TREASURE_T4)
			|| (tiles[t]->get_type() >= TILE_TREASURE_T5) && (tiles[t]->get_type() <= TILE_TREASURE_T5)
			|| (tiles[t]->get_type() >= TILE_TREASURE_T6) && (tiles[t]->get_type() <= TILE_TREASURE_T6)
			|| (tiles[t]->get_type() >= TILE_TREASURE_T7) && (tiles[t]->get_type() <= TILE_TREASURE_T7)
			|| (tiles[t]->get_type() >= TILE_TREASURE_T8) && (tiles[t]->get_type() <= TILE_TREASURE_T8))
		{
			//If the collision box touches the treasure tile
			if (check_collision(box, tiles[t]->get_box()) == true)
			{

				Mix_HaltChannel(-1);

				//Load image
				bground = SDL_LoadBMP("img/GameOver.bmp");

				//Apply image to screen
				SDL_BlitSurface(bground, NULL, screen, NULL);
				//Render the text
				message = TTF_RenderText_Solid(font2, "Quest Completed", textColor1);

				//If there was an error in rendering the text
				if (message == NULL)
				{
					return 1;
				}

				//Apply the images to the screen
				apply_surface(0, 0, bground, screen);
				apply_surface(585, 150, message, screen);

				//Update Screen
				SDL_Flip(screen);
				SDL_Delay(10000);
				
				return true;				
			}

		}
	if ((tiles[t]->get_type() >= TILE_DOOR_OPEN_LEFT_02) && (tiles[t]->get_type() <= TILE_DOOR_OPEN_LEFT_02))
			{
				//If the collision box touches the water tile
				if (check_collision(box, tiles[t]->get_box()) == true)
				{
					//The tile offsets
					int x = 0, y = 0;

					//Open the map
					std::ifstream map("map/Player1.map");

					//Initialize the tiles
					for (int t = 0; t < TOTAL_TILES; t++)
					{
						//Determines what kind of tile will be made
						int tileType = -1;

						//Read tile from map file
						map >> tileType;

						//If the was a problem in reading the map
						if (map.fail() == true)
						{
							//Stop loading map
							map.close();
							return false;
						}

						//If the number is a valid tile number
						if ((tileType >= 0) && (tileType < TILE_SPRITES))
						{
							tiles[t] = new Tile(x, y, tileType);
						}
						//If we don't recognize the tile type
						else
						{
							//Stop loading map
							map.close();
							return false;
						}

						//Move to next tile spot
						x += TILE_WIDTH;

						//If we've gone too far
						if (x >= LEVEL_WIDTH)
						{
							//Move back
							x = 0;

							//Move to the next row
							y += TILE_HEIGHT;
						}
					}

					//Close the file
					map.close();

					//If the map was loaded fine
					return true;
				}
			}	
		 if ((tiles[t]->get_type() >= TILE_DOOR_OPEN_RIGHT_02) && (tiles[t]->get_type() <= TILE_DOOR_OPEN_RIGHT_02))
			{
				//If the collision box touches the water tile
				if (check_collision(box, tiles[t]->get_box()) == true)
				{
					//The tile offsets
					int x = 0, y = 0;

					//Open the map
					std::ifstream map("map/Player2.map");

					//Initialize the tiles
					for (int t = 0; t < TOTAL_TILES; t++)
					{
						//Determines what kind of tile will be made
						int tileType = -1;

						//Read tile from map file
						map >> tileType;

						//If the was a problem in reading the map
						if (map.fail() == true)
						{
							//Stop loading map
							map.close();
							return false;
						}

						//If the number is a valid tile number
						if ((tileType >= 0) && (tileType < TILE_SPRITES))
						{
							tiles[t] = new Tile(x, y, tileType);
						}
						//If we don't recognize the tile type
						else
						{
							//Stop loading map
							map.close();
							return false;
						}

						//Move to next tile spot
						x += TILE_WIDTH;

						//If we've gone too far
						if (x >= LEVEL_WIDTH)
						{
							//Move back
							x = 0;

							//Move to the next row
							y += TILE_HEIGHT;
						}
					}

					//Close the file
					map.close();

					//If the map was loaded fine
					return true;
				}
			}
		 if ((tiles[t]->get_type() >= TILE_DOOR_OPEN_RIGHT_06) && (tiles[t]->get_type() <= TILE_DOOR_OPEN_RIGHT_06))
			{
				//If the collision box touches the water tile
				if (check_collision(box, tiles[t]->get_box()) == true)
				{
					//The tile offsets
					int x = 0, y = 0;

					//Open the map
					std::ifstream map("map/Player1_2.map");

					//Initialize the tiles
					for (int t = 0; t < TOTAL_TILES; t++)
					{
						//Determines what kind of tile will be made
						int tileType = -1;

						//Read tile from map file
						map >> tileType;

						//If the was a problem in reading the map
						if (map.fail() == true)
						{
							//Stop loading map
							map.close();
							return false;
						}

						//If the number is a valid tile number
						if ((tileType >= 0) && (tileType < TILE_SPRITES))
						{
							tiles[t] = new Tile(x, y, tileType);
						}
						//If we don't recognize the tile type
						else
						{
							//Stop loading map
							map.close();
							return false;
						}

						//Move to next tile spot
						x += TILE_WIDTH;

						//If we've gone too far
						if (x >= LEVEL_WIDTH)
						{
							//Move back
							x = 0;

							//Move to the next row
							y += TILE_HEIGHT;
						}
					}

					//Close the file
					map.close();

					//If the map was loaded fine
					return true;
				}
			}
		 if ((tiles[t]->get_type() >= TILE_DOOR_OPEN_LEFT_06) && (tiles[t]->get_type() <= TILE_DOOR_OPEN_LEFT_06))
		 {
			 //If the collision box touches the water tile
			 if (check_collision(box, tiles[t]->get_box()) == true)
			 {
				 //The tile offsets
				 int x = 0, y = 0;

				 //Open the map
				 std::ifstream map("map/Player1_2.map");

				 //Initialize the tiles
				 for (int t = 0; t < TOTAL_TILES; t++)
				 {
					 //Determines what kind of tile will be made
					 int tileType = -1;

					 //Read tile from map file
					 map >> tileType;

					 //If the was a problem in reading the map
					 if (map.fail() == true)
					 {
						 //Stop loading map
						 map.close();
						 return false;
					 }

					 //If the number is a valid tile number
					 if ((tileType >= 0) && (tileType < TILE_SPRITES))
					 {
						 tiles[t] = new Tile(x, y, tileType);
					 }
					 //If we don't recognize the tile type
					 else
					 {
						 //Stop loading map
						 map.close();
						 return false;
					 }

					 //Move to next tile spot
					 x += TILE_WIDTH;

					 //If we've gone too far
					 if (x >= LEVEL_WIDTH)
					 {
						 //Move back
						 x = 0;

						 //Move to the next row
						 y += TILE_HEIGHT;
					 }
				 }

				 //Close the file
				 map.close();

				 //If the map was loaded fine
				 return true;
			 }
		 }
			
		
		if ((tiles[t]->get_type() >= TILE_KEY_LEFT) && (tiles[t]->get_type() <= TILE_KEY_LEFT))
		{
			//If the collision box touches the water tile
			if (check_collision(box, tiles[t]->get_box()) == true)
			{
				//The tile offsets
				int x = 0, y = 0;

				//Open the map
				std::ifstream map("map/Player1.1.map");

				//Initialize the tiles
				for (int t = 0; t < TOTAL_TILES; t++)
				{
					//Determines what kind of tile will be made
					int tileType = -1;

					//Read tile from map file
					map >> tileType;

					//If the was a problem in reading the map
					if (map.fail() == true)
					{
						//Stop loading map
						map.close();
						return false;
					}

					//If the number is a valid tile number
					if ((tileType >= 0) && (tileType < TILE_SPRITES))
					{
						tiles[t] = new Tile(x, y, tileType);
					}
					//If we don't recognize the tile type
					else
					{
						//Stop loading map
						map.close();
						return false;
					}

					//Move to next tile spot
					x += TILE_WIDTH;

					//If we've gone too far
					if (x >= LEVEL_WIDTH)
					{
						//Move back
						x = 0;

						//Move to the next row
						y += TILE_HEIGHT;
					}
				}

				//Close the file
				map.close();

				//If the map was loaded fine
				return true;
			}
		}
		if ((tiles[t]->get_type() >= TILE_KEY_LEFT_01) && (tiles[t]->get_type() <= TILE_KEY_LEFT_01))
		{
			//If the collision box touches the water tile
			if (check_collision(box, tiles[t]->get_box()) == true)
			{
				//The tile offsets
				int x = 0, y = 0;

				//Open the map
				std::ifstream map("map/Player1_2_1.map");

				//Initialize the tiles
				for (int t = 0; t < TOTAL_TILES; t++)
				{
					//Determines what kind of tile will be made
					int tileType = -1;

					//Read tile from map file
					map >> tileType;

					//If the was a problem in reading the map
					if (map.fail() == true)
					{
						//Stop loading map
						map.close();
						return false;
					}

					//If the number is a valid tile number
					if ((tileType >= 0) && (tileType < TILE_SPRITES))
					{
						tiles[t] = new Tile(x, y, tileType);
					}
					//If we don't recognize the tile type
					else
					{
						//Stop loading map
						map.close();
						return false;
					}

					//Move to next tile spot
					x += TILE_WIDTH;

					//If we've gone too far
					if (x >= LEVEL_WIDTH)
					{
						//Move back
						x = 0;

						//Move to the next row
						y += TILE_HEIGHT;
					}
				}

				//Close the file
				map.close();

				//If the map was loaded fine
				return true;
			}
		}
		if ((tiles[t]->get_type() >= TILE_KEY_RIGHT_01) && (tiles[t]->get_type() <= TILE_KEY_RIGHT_01))
		{
			//If the collision box touches the water tile
			if (check_collision(box, tiles[t]->get_box()) == true)
			{
				//The tile offsets
				int x = 0, y = 0;

				//Open the map
				std::ifstream map("map/Player1_2_1.map");

				//Initialize the tiles
				for (int t = 0; t < TOTAL_TILES; t++)
				{
					//Determines what kind of tile will be made
					int tileType = -1;

					//Read tile from map file
					map >> tileType;

					//If the was a problem in reading the map
					if (map.fail() == true)
					{
						//Stop loading map
						map.close();
						return false;
					}

					//If the number is a valid tile number
					if ((tileType >= 0) && (tileType < TILE_SPRITES))
					{
						tiles[t] = new Tile(x, y, tileType);
					}
					//If we don't recognize the tile type
					else
					{
						//Stop loading map
						map.close();
						return false;
					}

					//Move to next tile spot
					x += TILE_WIDTH;

					//If we've gone too far
					if (x >= LEVEL_WIDTH)
					{
						//Move back
						x = 0;

						//Move to the next row
						y += TILE_HEIGHT;
					}
				}

				//Close the file
				map.close();

				//If the map was loaded fine
				return true;
			}
		}
		if ((tiles[t]->get_type() >= TILE_KEY_RIGHT) && (tiles[t]->get_type() <= TILE_KEY_RIGHT))
		{
			//If the collision box touches the water tile
			if (check_collision(box, tiles[t]->get_box()) == true)
			{
				//The tile offsets
				int x = 0, y = 0;

				//Open the map
				std::ifstream map("map/Player2.2.map");

				//Initialize the tiles
				for (int t = 0; t < TOTAL_TILES; t++)
				{
					//Determines what kind of tile will be made
					int tileType = -1;

					//Read tile from map file
					map >> tileType;

					//If the was a problem in reading the map
					if (map.fail() == true)
					{
						//Stop loading map
						map.close();
						return false;
					}

					//If the number is a valid tile number
					if ((tileType >= 0) && (tileType < TILE_SPRITES))
					{
						tiles[t] = new Tile(x, y, tileType);
					}
					//If we don't recognize the tile type
					else
					{
						//Stop loading map
						map.close();
						return false;
					}

					//Move to next tile spot
					x += TILE_WIDTH;

					//If we've gone too far
					if (x >= LEVEL_WIDTH)
					{
						//Move back
						x = 0;

						//Move to the next row
						y += TILE_HEIGHT;
					}
				}

				//Close the file
				map.close();

				//If the map was loaded fine
				return true;
			}
		}		
	}

	//If no wall tiles were touched
	return false;
}

Tile::Tile(int x, int y, int tileType)
{
	//Get the offsets
	box.x = x;
	box.y = y;

	//Set the collision box
	box.w = 18;
	box.h = 18;

	//Get the tile type
	type = tileType;
}

void Tile::show()
{
	//If the tile is on screen
	if (check_collision(Surface, box) == true)
	{
		//Show the tile
		apply_surface(box.x - Surface.x, box.y - Surface.y, tileSheet, screen, &clips[type]);
	}
}

int Tile::get_type()
{
	return type;
}

SDL_Rect Tile::get_box()
{
	return box;
}

Image1::Image1()
{
	//Initialize movement variables
	xMove1 = 20;
	yMove1 = 745;
	xVel1 = 0;
	yVel1 = 0;

	//Initialize the offsets
	box.x = 20;
	box.y = 745;

	//Set the square's dimentions
	box.w = IMG_WIDTH;
	box.h = IMG_HEIGHT;
	//Initialize animation variables
	frame1 = 0;
	status1 = IMG_RIGHT;
}

Image2::Image2()
{
	//Initialize movement variables
	xMove2 = 1320;
	yMove2 = 745;
	xVel2 = 0;
	yVel2 = 0;

	//Initialize the offsets
	box.x = 1320;
	box.y = 745;

	//Set the square's dimentions
	box.w = IMG_WIDTH;
	box.h = IMG_HEIGHT;
	//Initialize animation variables
	frame2 = 0;
	status2 = IMG_LEFT;
}

void Image1::handle_events1()
{
	//If a key was pressed
	if (event.type == SDL_KEYDOWN)
	{
		//Set the velocity
		switch (event.key.keysym.sym)
		{

		case SDLK_w: yVel1 -= IMG_HEIGHT / 6; break;
		case SDLK_s: yVel1 += IMG_HEIGHT / 6; break;
		case SDLK_a: xVel1 -= IMG_WIDTH / 6; break;
		case SDLK_d: xVel1 += IMG_WIDTH / 6; break;
		}
	}
	//If a key was released
	else if (event.type == SDL_KEYUP)
	{
		//sSet the velocity
		switch (event.key.keysym.sym)
		{
		case SDLK_w: yVel1 += IMG_HEIGHT / 6; break;
		case SDLK_s: yVel1 -= IMG_HEIGHT / 6; break;
		case SDLK_a: xVel1 += IMG_WIDTH / 6; break;
		case SDLK_d: xVel1 -= IMG_WIDTH / 6; break;
		}
	}

/*	//If a axis was changed
	if (event.type == SDL_JOYAXISMOTION)
	{
		//If joystick 0 has moved
		if (event.jaxis.which == 0)
		{
			//If the X axis changed
			if (event.jaxis.axis == 0)
			{
				//If the X axis is neutral
				if ((event.jaxis.value > -8000) && (event.jaxis.value < 8000))
				{
					xVel1 = 0;
				}
				//If not
				else
				{
					//Adjust the velocity
					if (event.jaxis.value < 0)
					{
						xVel1 = -IMG_WIDTH / 8;
					}
					else
					{
						xVel1 = IMG_WIDTH / 8;
					}
				}
			}
			//If the Y axis changed
			else if (event.jaxis.axis == 1)
			{
				//If the Y axis is neutral
				if ((event.jaxis.value > -8000) && (event.jaxis.value < 8000))
				{
					yVel1 = 0;
				}
				//If not
				else
				{
					//Adjust the velocity
					if (event.jaxis.value < 0)
					{
						yVel1 = -IMG_HEIGHT / 8;
					}
					else
					{
						yVel1 = IMG_HEIGHT / 8;
					}
				}
			}
		}
	}*/
}

void Image2::handle_events2()
{
	//If a key was pressed
	if (event.type == SDL_KEYDOWN)
	{
		//Set the velocity
		switch (event.key.keysym.sym)
		{

		case SDLK_UP: yVel2 -= IMG_HEIGHT / 6; break;
		case SDLK_DOWN: yVel2 += IMG_HEIGHT / 6; break;
		case SDLK_LEFT: xVel2 -= IMG_WIDTH / 6; break;
		case SDLK_RIGHT: xVel2 += IMG_WIDTH / 6; break;
		}
	}
	//If a key was released
	else if (event.type == SDL_KEYUP)
	{
		//sSet the velocity
		switch (event.key.keysym.sym)
		{
		case SDLK_UP: yVel2 += IMG_HEIGHT / 6; break;
		case SDLK_DOWN: yVel2 -= IMG_HEIGHT / 6; break;
		case SDLK_LEFT: xVel2 += IMG_WIDTH / 6; break;
		case SDLK_RIGHT: xVel2 -= IMG_WIDTH / 6; break;
		}
	}
/*	//If a axis was changed
	if (event.type == SDL_JOYAXISMOTION)
	{
		//If joystick 0 has moved
		if (event.jaxis.which == 1)
		{
			//If the X axis changed
			if (event.jaxis.axis == 0)
			{
				//If the X axis is neutral
				if ((event.jaxis.value > -8000) && (event.jaxis.value < 8000))
				{
					xVel2 = 0;
				}
				//If not
				else
				{
					//Adjust the velocity
					if (event.jaxis.value < 0)
					{
						xVel2 = -IMG_WIDTH / 8;
					}
					else
					{
						xVel2 = IMG_WIDTH / 8;
					}
				}
			}
			//If the Y axis changed
			else if (event.jaxis.axis == 1)
			{
				//If the Y axis is neutral
				if ((event.jaxis.value > -8000) && (event.jaxis.value < 8000))
				{
					yVel2 = 0;
				}
				//If not
				else
				{
					//Adjust the velocity
					if (event.jaxis.value < 0)
					{
						yVel2 = -IMG_HEIGHT / 8;
					}
					else
					{
						yVel2 = IMG_HEIGHT / 8;
					}
				}
			}
		}
	}*/
}

Enemy_Rect::Enemy_Rect(int x, int y, int i, int j)
{
	//Initialize the offsets
	ebox.x = x;
	ebox.y = y;
	ebox.w = ENEMY_WIDTH;
	ebox.h = ENEMY_HEIGHT;

	//Initialize the velocity
	eVelx = i;
	eVely = j;
}

void Image1::move1(Tile *tiles[])
{

	//Move the Image1 left or right
	xMove1 += xVel1;
	box.x += xVel1;

	//If the Image1 went too far to the left or right
	if ((xMove1 < 0) || (xMove1 + IMG_WIDTH > SCREEN_WIDTH) || touches_wall(box, tiles))
	{
		//move back
		xMove1 -= xVel1;
		box.x -= xVel1;
	}

	//Move the Image1 up or down
	yMove1 += yVel1;
	box.y += yVel1;

	//If the Image1 went too far up or down
	if ((yMove1 < 0) || (yMove1 + IMG_HEIGHT > SCREEN_HEIGHT) || touches_wall(box, tiles))
	{
		//move back
		yMove1 -= yVel1;
		box.y -= yVel1;

	}
}

void Image2::move2(Tile *tiles[])
{

	//Move the Image1 left or right
	xMove2 += xVel2;
	box.x += xVel2;

	//If the Image1 went too far to the left or right
	if ((xMove2 < 0) || (xMove2 + IMG_WIDTH > SCREEN_WIDTH) || touches_wall(box, tiles))
	{
		//move back
		xMove2 -= xVel2;
		box.x -= xVel2;
	}

	//Move the Image1 up or down
	yMove2 += yVel2;
	box.y += yVel2;

	//If the Image1 went too far up or down
	if ((yMove2 < 0) || (yMove2 + IMG_HEIGHT > SCREEN_HEIGHT) || touches_wall(box, tiles))
	{
		//move back
		yMove2 -= yVel2;
		box.y -= yVel2;

	}

}

void Enemy_Rect::emove(int a, int b, Tile *tiles[])
{

	//Move the dot left or right
	ebox.x += eVelx;

	//If the dot went too far to the left or right or touched a wall
	if ((ebox.x < 0) || (ebox.x + ENEMY_WIDTH > 728) || touches_wall(ebox, tiles))
	{
		//Initialize the velocity
		eVelx = -a;
		eVely = b;
	}
	//If the dot went too far to the left or right or touched a wall
	if ((ebox.x < 0) || (ebox.x + ENEMY_WIDTH < 653) || touches_wall(ebox, tiles))
	{
		//Initialize the velocity
		eVelx = a;
		eVely = b;
	}

}
void Image1::show1()
{
	//If Image is moving left
	if (xVel1 < 0)
	{
		//Set the animation to left
		status1 = IMG_LEFT;

		//Move to the next frame in the animation
		frame1++;
	}
	//If Image is moving right
	else if (xVel1 > 0)
	{
		//Set the animation to right
		status1 = IMG_RIGHT;

		//Move to the next frame in the animation
		frame1++;
	}
	else if (yVel1 < 0)
	{
		//Set the animation to up
		status1 = IMG_UP;

		//Move to the next frame in the animation
		frame1++;
	}
	//If Image is moving down
	else if (yVel1 > 0)
	{
		//Set the animation to down
		status1 = IMG_DOWN;

		//Move to the next frame in the animation
		frame1++;
	}
	//If Image standing
	else
	{
		//Restart the animation
		frame1 = 0;
	}

	//Loop the animation
	if (frame1 >= 4)
	{
		frame1 = 0;
	}

	//Show the Image
	if (status1 == IMG_RIGHT)
	{
		apply_surface(xMove1, yMove1, player1, screen, &clipsRight[frame1]);
	}
	else if (status1 == IMG_LEFT)
	{
		apply_surface(xMove1, yMove1, player1, screen, &clipsLeft[frame1]);
	}
	else if (status1 == IMG_UP)
	{
		apply_surface(xMove1, yMove1, player1, screen, &clipsUp[frame1]);
	}
	else if (status1 == IMG_DOWN)
	{
		apply_surface(xMove1, yMove1, player1, screen, &clipsDown[frame1]);
	}
}


void Image2::show2()
{
	//If Image is moving left
	if (xVel2 < 0)
	{
		//Set the animation to left
		status2 = IMG_LEFT;

		//Move to the next frame in the animation
		frame2++;
	}
	//If Image is moving right
	else if (xVel2 > 0)
	{
		//Set the animation to right
		status2 = IMG_RIGHT;

		//Move to the next frame in the animation
		frame2++;
	}
	else if (yVel2 < 0)
	{
		//Set the animation to up
		status2 = IMG_UP;

		//Move to the next frame in the animation
		frame2++;
	}
	//If Image is moving down
	else if (yVel2 > 0)
	{
		//Set the animation to down
		status2 = IMG_DOWN;

		//Move to the next frame in the animation
		frame2++;
	}
	//If Image standing
	else
	{
		//Restart the animation
		frame2 = 0;
	}

	//Loop the animation
	if (frame2 >= 4)
	{
		frame2 = 0;
	}

	//Show the Image
	if (status2 == IMG_RIGHT)
	{
		apply_surface(xMove2, yMove2, player2, screen, &clipsRight[frame2]);
	}
	else if (status2 == IMG_LEFT)
	{
		apply_surface(xMove2, yMove2, player2, screen, &clipsLeft[frame2]);
	}
	else if (status2 == IMG_UP)
	{
		apply_surface(xMove2, yMove2, player2, screen, &clipsUp[frame2]);
	}
	else if (status2 == IMG_DOWN)
	{
		apply_surface(xMove2, yMove2, player2, screen, &clipsDown[frame2]);
	}
}

void Enemy_Rect::eshow()
{
	//Show the dot
	apply_surface(ebox.x, ebox.y , enemy, screen);
}

void Image1::set_Surface1()
{
	if (status1 == IMG_RIGHT && (box.x - Surface.x) >= SCREEN_WIDTH / 2){

		Surface.x += xVel1;

		if (Surface.x <= LEVEL_WIDTH - SCREEN_WIDTH) xMove1 -= xVel1;

	}

	else if (status1 == IMG_LEFT && (box.x - Surface.x) <= SCREEN_WIDTH / 2){

		Surface.x += xVel1;

		if (Surface.x >= 0) xMove1 -= xVel1;

	}

	else if (status1 == IMG_DOWN && (box.y - Surface.y) >= SCREEN_HEIGHT / 2){

		Surface.y += yVel1;

		if (Surface.y <= LEVEL_HEIGHT - SCREEN_HEIGHT) yMove1 -= yVel1;

	}

	else if (status1 == IMG_UP && (box.y + box.h / 2 - Surface.y) <= SCREEN_HEIGHT / 2){

		Surface.y += yVel1;

		if (Surface.y >= 0) yMove1 -= yVel1;
	}

	//Keep the Surface in bounds.
	if (Surface.x < 0)
	{
		Surface.x = 0;
	}
	if (Surface.y < 0)
	{
		Surface.y = 0;
	}
	if (Surface.x > LEVEL_WIDTH - Surface.w)
	{
		Surface.x = LEVEL_WIDTH - Surface.w;
	}
	if (Surface.y > LEVEL_HEIGHT - Surface.h)
	{
		Surface.y = LEVEL_HEIGHT - Surface.h;
	}
}


void Image2::set_Surface2()
{
	if (status2 == IMG_RIGHT && (box.x - Surface.x) >= SCREEN_WIDTH / 2){

		Surface.x += xVel2;

		if (Surface.x <= LEVEL_WIDTH - SCREEN_WIDTH) xMove2 -= xVel2;

	}

	else if (status2 == IMG_LEFT && (box.x - Surface.x) <= SCREEN_WIDTH / 2){

		Surface.x += xVel2;

		if (Surface.x >= 0) xMove2 -= xVel2;

	}

	else if (status2 == IMG_DOWN && (box.y - Surface.y) >= SCREEN_HEIGHT / 2){

		Surface.y += yVel2;

		if (Surface.y <= LEVEL_HEIGHT - SCREEN_HEIGHT) yMove2 -= yVel2;

	}

	else if (status2 == IMG_UP && (box.y + box.h / 2 - Surface.y) <= SCREEN_HEIGHT / 2){

		Surface.y += yVel2;

		if (Surface.y >= 0) yMove2 -= yVel2;
	}



	//Keep the camera in bounds.
	if (Surface.x < 0)
	{
		Surface.x = 0;
	}
	if (Surface.y < 0)
	{
		Surface.y = 0;
	}
	if (Surface.x > LEVEL_WIDTH - Surface.w)
	{
		Surface.x = LEVEL_WIDTH - Surface.w;
	}
	if (Surface.y > LEVEL_HEIGHT - Surface.h)
	{
		Surface.y = LEVEL_HEIGHT - Surface.h;
	}
}


Timer::Timer()
{
	//Initialize the variables
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}

void Timer::start()
{
	//Start the timer
	started = true;

	//Unpause the timer
	paused = false;

	//Get the current clock time
	startTicks = SDL_GetTicks();
}

void Timer::stop()
{
	//Stop the timer
	started = false;

	//Unpause the timer
	paused = false;
}

void Timer::pause()
{
	//If the timer is running and isn't already paused
	if ((started == true) && (paused == false))
	{
		//Pause the timer
		paused = true;

		//Calculate the paused ticks
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void Timer::unpause()
{
	//If the timer is paused
	if (paused == true)
	{
		//Unpause the timer
		paused = false;

		//Reset the starting ticks
		startTicks = SDL_GetTicks() - pausedTicks;

		//Reset the paused ticks
		pausedTicks = 0;
	}
}

int Timer::get_ticks()
{
	//If the timer is running
	if (started == true)
	{
		//If the timer is paused
		if (paused == true)
		{
			//Return the number of ticks when the timer was paused
			return pausedTicks;
		}
		else
		{
			//Return the current time minus the start time
			return SDL_GetTicks() - startTicks;
		}
	}

	//If the timer isn't running
	return 0;
}

bool Timer::is_started()
{
	return started;
}

bool Timer::is_paused()
{
	return paused;
}


#endif