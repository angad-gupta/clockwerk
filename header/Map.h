#ifndef MAP_H
#define MAP_H

#include "Header.h"
#include <fstream>

bool set_tiles(Tile *tiles[])
{
	//The tile offsets
	int x = 0, y = 0;

	//Open the map
	std::ifstream map("map/clockwerk.map");

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

#endif