#include "../include/app.h"
#include <raylib.h>
#include <string>

void initApp(int width, int height, std::string appname)
{
	InitWindow(width, height, appname.c_str());
}

void setWindowIcon(std::string path_to_img)
{
	SetWindowIcon(LoadImage(path_to_img.c_str()));
}

void putImage(std::string path_to_img, int posx, int posy, Color tint)
{
	static Image banner_img;
	static Texture2D banner_tex;
	
	if (banner_img.data == NULL || banner_tex.id == 0)
	{
		banner_img = LoadImage(path_to_img.c_str());
		banner_tex = LoadTextureFromImage(banner_img);
		UnloadImage(banner_img);
	}
	
	DrawTexture(banner_tex, posx, posy, WHITE);
}

void destroyApp()
{
	CloseWindow();
}