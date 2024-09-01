#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


class Map {
public:
	Map();


	void LoadMap(int arr[128][160]);
	void DrawMap();
	void Updater();
	int Win();
	void ResetAll();
	void MousePress(SDL_MouseButtonEvent& b);
private:
	SDL_Rect src[15], dest[15];
	SDL_Rect srcx[25], destx[25];
	SDL_Rect srco[25], desto[25];
	SDL_Texture* reset;
	SDL_Texture* xwon;
	SDL_Texture* owon;
	SDL_Texture* lineup1;
	SDL_Texture* lineup2;
	SDL_Texture* lineright1;
	SDL_Texture* lineright2;
	SDL_Texture* x[20];
	SDL_Texture* o[20];

	int map[128][160];
};