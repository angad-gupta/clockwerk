#ifndef GAMEVARIABLE_H
#define GAMEVARIABLE_H

//The joystick that will be used
SDL_Joystick *stick1 = NULL, *stick2 = NULL;

//The Screen
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;
const int SCREEN_BPP = 32;

//The frames per second
const int FRAMES_PER_SECOND = 100;

//The dimenstions of the sprites photo
const int IMG_WIDTH = 20;
const int IMG_HEIGHT = 20;
//The dot dimensions
const int ENEMY_WIDTH = 20;
const int ENEMY_HEIGHT = 20;

//The direction status of the white
const int IMG_LEFT = 1;
const int IMG_RIGHT = 2;
const int IMG_UP = 3;
const int IMG_DOWN = 4;

//The dimensions of the level
const int LEVEL_WIDTH = 1366;
const int LEVEL_HEIGHT = 768;

//Tile constants
const int TILE_WIDTH = 20;
const int TILE_HEIGHT = 20;
const int TOTAL_TILES = 2691;
const int TILE_SPRITES = 200;

//The different tile sprites
const int TILE_PATH = 0;
const int TILE_BLOCK = 1;
const int TILE_TREASURE_T1 = 2;
const int TILE_TREASURE_T2 = 3;
const int TILE_TREASURE_T3 = 4;
const int TILE_TREASURE_T4 = 5;
const int TILE_TREASURE_T5 = 6;
const int TILE_TREASURE_T6 = 7;
const int TILE_TREASURE_T7 = 8;
const int TILE_TREASURE_T8 = 9;
const int TILE_WATER_00 = 11;
const int TILE_WATER_01 = 10;
const int TILE_CAVE_00 = 12;
const int TILE_CAVE_01 = 13;
const int TILE_CAVE_10 = 14;
const int TILE_CAVE_11 = 15;
const int TILE_RAMP = 16;
const int TILE_ROCK = 17;
const int TILE_COCONUT_00 = 18;
const int TILE_COCONUT_01 = 19;
const int TILE_COCONUT_10 = 20;
const int TILE_COCONUT_11 = 21;
const int TILE_POUND_RIGHT_P1 = 22;
const int TILE_POUND_RIGHT_P2 = 23;
const int TILE_POUND_RIGHT_P3 = 24;
const int TILE_POUND_RIGHT_P4 = 25;
const int TILE_POUND_RIGHT_P5 = 26;
const int TILE_POUND_RIGHT_P6 = 27;
const int TILE_POUND_RIGHT_P7 = 28;
const int TILE_POUND_RIGHT_P8 = 29;
const int TILE_POUND_RIGHT_P9 = 30;
const int TILE_POUND_RIGHT_P10 = 31;
const int TILE_POUND_RIGHT_P11 = 32;
const int TILE_POUND_RIGHT_P12 = 33;
const int TILE_POUND_RIGHT_P13 = 34;
const int TILE_POUND_RIGHT_P14 = 35;
const int TILE_POUND_RIGHT_P15 = 36;
const int TILE_POUND_RIGHT_P16 = 37;
const int TILE_POUND_RIGHT_P17 = 38;
const int TILE_POUND_RIGHT_P18 = 39;
const int TILE_POUND_RIGHT_P19 = 40;
const int TILE_POUND_RIGHT_P20 = 41;
const int TILE_POUND_RIGHT_P21 = 42;
const int TILE_POUND_RIGHT_P22 = 43;
const int TILE_POUND_RIGHT_P23 = 44;
const int TILE_POUND_RIGHT_P24 = 45;
const int TILE_POUND_LEFT_P1 = 46;
const int TILE_POUND_LEFT_P2 = 47;
const int TILE_POUND_LEFT_P3 = 48;
const int TILE_POUND_LEFT_P4 = 49;
const int TILE_POUND_LEFT_P5 = 50;
const int TILE_POUND_LEFT_P6 = 51;
const int TILE_POUND_LEFT_P7 = 52;
const int TILE_POUND_LEFT_P8 = 53;
const int TILE_POUND_LEFT_P9 = 54;
const int TILE_POUND_LEFT_P10 = 55;
const int TILE_POUND_LEFT_P11 = 56;
const int TILE_POUND_LEFT_P12 = 57;
const int TILE_POUND_LEFT_P13 = 58;
const int TILE_POUND_LEFT_P14 = 59;
const int TILE_POUND_LEFT_P15 = 60;
const int TILE_POUND_LEFT_P16 = 61;
const int TILE_POUND_LEFT_P17 = 62;
const int TILE_POUND_LEFT_P18 = 63;
const int TILE_POUND_LEFT_P19 = 64;
const int TILE_POUND_LEFT_P20 = 65;
const int TILE_POUND_LEFT_P21 = 66;
const int TILE_POUND_LEFT_P22 = 67;
const int TILE_POUND_LEFT_P23 = 68;
const int TILE_POUND_LEFT_P24 = 69;
const int TILE_KEY_LEFT = 70;
const int TILE_KEY_RIGHT = 71;
const int TILE_DOOR_OPEN_LEFT_01 = 72;
const int TILE_DOOR_OPEN_LEFT_02 = 73;
const int TILE_DOOR_OPEN_RIGHT_01 = 74;
const int TILE_DOOR_OPEN_RIGHT_02 = 75;
const int TILE_DOOR_OPEN_LEFT_03 = 76;
const int TILE_DOOR_OPEN_LEFT_04 = 77;
const int TILE_DOOR_OPEN_RIGHT_03 = 78;
const int TILE_DOOR_OPEN_RIGHT_04 = 79;
const int TILE_DOOR_OPEN_LEFT_05 = 80;
const int TILE_DOOR_OPEN_LEFT_06 = 81;
const int TILE_DOOR_OPEN_RIGHT_05 = 82;
const int TILE_DOOR_OPEN_RIGHT_06 = 83;
const int TILE_KEY_LEFT_01 = 84;
const int TILE_KEY_RIGHT_01 = 85;
const int TILE_ENEMY = 86;


//The surfaces
SDL_Surface *player1 = NULL, *player2 = NULL, *enemy = NULL;
SDL_Surface *screen = NULL, *screen1 = NULL, *bground = NULL, *tileSheet = NULL, *seconds = NULL;
SDL_Rect Surface = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
SDL_Surface *message = NULL;

//The event structure
SDL_Event event;

//Sprite from the tile sheet
SDL_Rect clips[TILE_SPRITES];

//The areas of the sprite sheet
SDL_Rect clipsRight[4];
SDL_Rect clipsLeft[4];
SDL_Rect clipsUp[4];
SDL_Rect clipsDown[4];

//The font
TTF_Font *font = NULL, *font1 = NULL, *font2 = NULL;

//The color of the font
SDL_Color textColor = { 0xFF, 0xFF, 0xFF };
SDL_Color textColor1 = { 0xFF, 0x00, 0x00 };

//The Music
int channel;
int audio_rate = 22050;
Uint16 audio_format = AUDIO_S16SYS;
int audio_channels = 2;
int audio_buffers = 4096;
Mix_Chunk *sound = NULL, *sound1 = NULL;

//The button states in the sprite sheet
const int CLIP_MOUSEOVER = 0;
const int CLIP_MOUSEOUT = 1;
const int CLIP_MOUSEDOWN = 2;
const int CLIP_MOUSEUP = 3;

//The surfaces
SDL_Surface *mybutton1 = NULL;

//The clip regions of the sprite sheet
SDL_Rect clips_button[4];

//The CAVE dimensions
const int CAVE_WIDTH = 80;
const int CAVE_HEIGHT = 50;

#endif