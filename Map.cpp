#include "Map.h"
#include "game.h"
#include <fstream>
#include "TextureManager.h"
#include <cmath>



const Uint8* keystates = SDL_GetKeyboardState(NULL);
int keypressed[200];
int timepressed[200];
int level = 1, coincount = 0;
int constant[200];
int timestart[200];
int screen[128][160];
int ok[200];
int length = 100;
int speed = 4;
int mouseX, mouseY;
int turn = 1;
int xturn = 1, oturn = 1;
int placed[10][10];


Map::Map()
{
	reset = TextureManager::LoadTexture("C:\\Users\\ahmad\\Downloads\\resetbutttt.png");
	xwon = TextureManager::LoadTexture("C:\\Users\\ahmad\\Downloads\\xwonttt.png");
	owon = TextureManager::LoadTexture("C:\\Users\\ahmad\\Downloads\\owonttt.png");
	lineup1 = TextureManager::LoadTexture("C:\\Users\\ahmad\\Downloads\\lineupttt.png");
	lineup2 = TextureManager::LoadTexture("C:\\Users\\ahmad\\Downloads\\lineupttt.png");
	lineright1 = TextureManager::LoadTexture("C:\\Users\\ahmad\\Downloads\\linerightttt.png");
	lineright2 = TextureManager::LoadTexture("C:\\Users\\ahmad\\Downloads\\linerightttt.png");
	for (int i = 1; i <= 15; ++i)
	{
		x[i] = TextureManager::LoadTexture("C:\\Users\\ahmad\\Downloads\\xttt.png");
		o[i] = TextureManager::LoadTexture("C:\\Users\\ahmad\\Downloads\\0ttt.png");
	}
	LoadMap(screen);

	src[5].x = 0;
	src[5].y = 0;
	src[5].w = 100;
	src[5].h = 30;
	dest[5].x = 650;
	dest[5].y = 10;
	dest[5].w = 100;
	dest[5].h = 30;

	src[6].x = 0;
	src[6].y = 0;
	src[6].w = 100;
	src[6].h = 30;
	dest[6].x = -350;
	dest[6].y = -305;
	dest[6].w = 100;
	dest[6].h = 30;

	src[7].x = 0;
	src[7].y = 0;
	src[7].w = 100;
	src[7].h = 30;
	dest[7].x = -350;
	dest[7].y = -305;
	dest[7].w = 100;
	dest[7].h = 30;

	src[1].x = 0;
	src[1].y = 0;
	src[1].w = 20;
	src[1].h = 640;
	dest[1].x = 256;
	dest[1].y = 0;
	dest[1].w = 20;
	dest[1].h = 640;

	src[2].x = 0;
	src[2].y = 0;
	src[2].w = 20;
	src[2].h = 640;
	dest[2].x = 522;
	dest[2].y = 0;
	dest[2].w = 20;
	dest[2].h = 640;

	src[3].x = 0;
	src[3].y = 0;
	src[3].w = 800;
	src[3].h = 20;
	dest[3].x = 0;
	dest[3].y = 203;
	dest[3].w = 800;
	dest[3].h = 20;

	src[4].x = 0;
	src[4].y = 0;
	src[4].w = 800;
	src[4].h = 20;
	dest[4].x = 0;
	dest[4].y = 416;
	dest[4].w = 800;
	dest[4].h = 20;



	for (int i = 1; i <= 15; ++i)
	{
		srcx[i].x = 0;
		srcx[i].y = 0;
		srcx[i].w = 256;
		srcx[i].h = 203;
		destx[i].x = -400;
		destx[i].y = -400;
		destx[i].w = 256;
		destx[i].h = 203;

		srco[i].x = 0;
		srco[i].y = 0;
		srco[i].w = 256;
		srco[i].h = 203;
		desto[i].x = -400;
		desto[i].y = -400;
		desto[i].w = 256;
		desto[i].h = 203;
	}



}
// sin(0)=0  sin(pi/2) = 1 
//w 800 h 640

void Map::ResetAll()
{
	src[6].x = 0;
	src[6].y = 0;
	src[6].w = 100;
	src[6].h = 30;
	dest[6].x = -350;
	dest[6].y = -305;
	dest[6].w = 100;
	dest[6].h = 30;

	src[7].x = 0;
	src[7].y = 0;
	src[7].w = 100;
	src[7].h = 30;
	dest[7].x = -350;
	dest[7].y = -305;
	dest[7].w = 100;
	dest[7].h = 30;
	for (int i = 1; i <= 15; ++i)
	{
		srcx[i].x = 0;
		srcx[i].y = 0;
		srcx[i].w = 256;
		srcx[i].h = 203;
		destx[i].x = -400;
		destx[i].y = -400;
		destx[i].w = 256;
		destx[i].h = 203;

		srco[i].x = 0;
		srco[i].y = 0;
		srco[i].w = 256;
		srco[i].h = 203;
		desto[i].x = -400;
		desto[i].y = -400;
		desto[i].w = 256;
		desto[i].h = 203;
	}
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			placed[i][j] = 0;
		}
	}
}

void Map::MousePress(SDL_MouseButtonEvent& b) {
	if (b.button == SDL_BUTTON_LEFT) {
		//handle a left-click
		SDL_GetMouseState(&mouseX, &mouseY);
		std::cout << mouseX << " " << mouseY << std::endl;
		
	}
}

void Map::Updater()
{
	/*
	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			break;
		case SDL_MOUSEBUTTONDOWN:
			//do whatever you want to do after a mouse button was pressed,
			MousePress(e.button);
	
			break;

		}
	}
	*/
	if (Win() == 1)
	{
		dest[6].x = 350;
		dest[6].y = 305;
	}
	else if (Win() == 2)
	{
		dest[7].x = 350;
		dest[7].y = 305;
	}
	if (Win() != 0)
	{
		if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON_LMASK)
		{
			if (mouseX > dest[5].x && mouseX<dest[5].x + dest[5].w && mouseY>dest[5].y && mouseY < dest[5].y + dest[5].h)
			{
				ResetAll();
				xturn = 1;
				oturn = 1;
				turn = 1;
			}
		}
	}
	if (Win() == 0)
	{
		if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON_LMASK)
		{
			if (mouseX > dest[5].x && mouseX<dest[5].x + dest[5].w && mouseY>dest[5].y && mouseY < dest[5].y + dest[5].h)
			{
				ResetAll();
			}
			else
			{
				if (mouseX < 266 && mouseY < 213 && placed[1][1] == 0)
				{
					if (turn == 1)
					{
						destx[xturn].x = 0;
						destx[xturn].y = 0;
						xturn++;
						turn = 2;
						placed[1][1] = 1;
					}
					else if (turn == 2)
					{
						desto[oturn].x = 0;
						desto[oturn].y = 0;
						turn = 1;
						placed[1][1] = 2;
						oturn++;
					}
				}
				else if (mouseX < 266 && mouseY >= 213 && mouseY < 426 && placed[2][1] == 0)
				{
					if (turn == 1)
					{
						destx[xturn].x = 0;
						destx[xturn].y = 213;
						xturn++;
						placed[2][1] = 1;
						turn = 2;
					}
					else if (turn == 2)
					{
						desto[oturn].x = 0;
						desto[oturn].y = 213;
						turn = 1;
						placed[2][1] = 2;
						oturn++;
					}
				}
				else if (mouseX < 266 && mouseY >= 426 && mouseY < 640 && placed[3][1] == 0)
				{
					if (turn == 1)
					{
						destx[xturn].x = 0;
						destx[xturn].y = 426;
						xturn++;
						placed[3][1] = 1;
						turn = 2;
					}
					else if (turn == 2)
					{
						desto[oturn].x = 0;
						desto[oturn].y = 426;
						turn = 1;
						placed[3][1] = 2;
						oturn++;
					}
				}
				else if (mouseX >= 266 && mouseX < 532 && mouseY < 213 && placed[1][2] == 0)
				{
					if (turn == 1)
					{
						destx[xturn].x = 266;
						destx[xturn].y = 0;
						xturn++;
						placed[1][2] = 1;
						turn = 2;
					}
					else if (turn == 2)
					{
						desto[oturn].x = 266;
						desto[oturn].y = 0;
						turn = 1;
						placed[1][2] = 2;
						oturn++;
					}
				}
				else if (mouseX >= 266 && mouseX < 532 && mouseY >= 213 && mouseY < 426 && placed[2][2] == 0)
				{
					if (turn == 1)
					{
						destx[xturn].x = 266;
						destx[xturn].y = 213;
						xturn++;
						placed[2][2] = 1;
						turn = 2;
					}
					else if (turn == 2)
					{
						desto[oturn].x = 266;
						desto[oturn].y = 213;
						turn = 1;
						placed[2][2] = 2;
						oturn++;
					}
				}
				else if (mouseX >= 266 && mouseX < 532 && mouseY >= 426 && mouseY < 640 && placed[3][2] == 0)
				{
					if (turn == 1)
					{
						destx[xturn].x = 266;
						destx[xturn].y = 426;
						xturn++;
						placed[3][2] = 1;
						turn = 2;
					}
					else if (turn == 2)
					{
						desto[oturn].x = 266;
						desto[oturn].y = 426;
						turn = 1;
						placed[3][2] = 2;
						oturn++;
					}
				}
				else if (mouseX >= 532 && mouseX < 800 && mouseY < 213 && placed[1][3] == 0)
				{
					if (turn == 1)
					{
						destx[xturn].x = 532;
						destx[xturn].y = 0;
						xturn++;
						placed[1][3] = 1;
						turn = 2;
					}
					else if (turn == 2)
					{
						desto[oturn].x = 532;
						desto[oturn].y = 0;
						turn = 1;
						placed[1][3] = 2;
						oturn++;
					}
				}
				else if (mouseX >= 532 && mouseX < 800 && mouseY >= 213 && mouseY < 426 && placed[2][3] == 0)
				{
					if (turn == 1)
					{
						destx[xturn].x = 532;
						destx[xturn].y = 213;
						xturn++;
						placed[2][3] = 1;
						turn = 2;
					}
					else if (turn == 2)
					{
						desto[oturn].x = 532;
						desto[oturn].y = 213;
						turn = 1;
						placed[2][3] = 2;
						oturn++;
					}
				}
				else if (mouseX >= 532 && mouseX < 800 && mouseY >= 426 && mouseY < 640 && placed[3][3] == 0)
				{
					if (turn == 1)
					{
						destx[xturn].x = 532;
						destx[xturn].y = 426;
						xturn++;
						placed[3][3] = 1;
						turn = 2;
					}
					else if (turn == 2)
					{
						desto[oturn].x = 532;
						desto[oturn].y = 426;
						turn = 1;
						placed[3][3] = 2;
						oturn++;
					}
				}
			}
		}
	}
	else
	{
		if (Win() == 1)
		{

		}
	}
	/*
	if (keystates[SDL_SCANCODE_R])
	{
		desttable.w = -700;
		desttable.h = -460;
		desttable.x = -50;
		desttable.y = -40;
		srctable.x = srctable.y = 0;
		srctable.w = -700;
		srctable.h = -460;
	}
	if (keystates[SDL_SCANCODE_E])
	{
		desttable.w = 700;
		desttable.h = 460;
		desttable.x = 50;
		desttable.y = 40;
		srctable.x = srctable.y = 0;
		srctable.w = 700;
		srctable.h = 460;
	}
	*/
	DrawMap();
}

int Map::Win()
{
	if ((placed[1][1] == 1 && placed[1][2] == 1 && placed[1][3] == 1) ||
		(placed[2][1] == 1 && placed[2][2] == 1 && placed[2][3] == 1) ||
		(placed[3][1] == 1 && placed[3][2] == 1 && placed[3][3] == 1) ||
		(placed[1][1] == 1 && placed[2][1] == 1 && placed[3][1] == 1) ||
		(placed[1][2] == 1 && placed[2][2] == 1 && placed[3][2] == 1) ||
		(placed[1][3] == 1 && placed[2][3] == 1 && placed[3][3] == 1) ||
		(placed[1][1] == 1 && placed[2][2] == 1 && placed[3][3] == 1) ||
		(placed[1][3] == 1 && placed[2][2] == 1 && placed[3][1] == 1))
	{
		return 1;
	}
	if ((placed[1][1] == 2 && placed[1][2] == 2 && placed[1][3] == 2) ||
		(placed[2][1] == 2 && placed[2][2] == 2 && placed[2][3] == 2) ||
		(placed[3][1] == 2 && placed[3][2] == 2 && placed[3][3] == 2) ||
		(placed[1][1] == 2 && placed[2][1] == 2 && placed[3][1] == 2) ||
		(placed[1][2] == 2 && placed[2][2] == 2 && placed[3][2] == 2) ||
		(placed[1][3] == 2 && placed[2][3] == 2 && placed[3][3] == 2) ||
		(placed[1][1] == 2 && placed[2][2] == 2 && placed[3][3] == 2) ||
		(placed[1][3] == 2 && placed[2][2] == 2 && placed[3][1] == 2))
	{
		return 2;
	}
	return 0;
}

void Map::LoadMap(int arr[128][160])
{
	for (int row = 0; row < 128; ++row)
	{
		for (int column = 0; column < 160; ++column)
		{
			map[row][column] = arr[row][column];
		}
	}
}



void Map::DrawMap()
{
	TextureManager::Draw(reset, src[5], dest[5]);
	TextureManager::Draw(xwon, src[6], dest[6]);
	TextureManager::Draw(owon, src[7], dest[7]);
	TextureManager::Draw(lineup1, src[1], dest[1]);
	TextureManager::Draw(lineup2, src[2], dest[2]);
	TextureManager::Draw(lineright1, src[3], dest[3]);
	TextureManager::Draw(lineright2, src[4], dest[4]);
	for (int i = 1; i <= 15; ++i)
	{
		TextureManager::Draw(x[i], srcx[i], destx[i]);
		TextureManager::Draw(o[i], srco[i], desto[i]);
	}
	/*
	int type = 0;
	for (int row = 0; row < 128; ++row)
	{
		for (int column = 0; column < 160; ++column)
		{
			type = map[row][column];
			dest.x = column * 5;
			dest.y = row * 5;
			//TextureManager::Draw(coinage, src2, dest2);
			if (coincount == 0)
			{
			//	TextureManager::Draw(zero, src3, dest3);
			}

			switch (type)
			{
			case 0:
				TextureManager::Draw(sinedot, src, dest);
				break;
			default:
				break;
			}

		}
	}
	*/
}

