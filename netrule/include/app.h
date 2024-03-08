#pragma once

#include <raylib.h>
#include <string>

void initApp(int width, int height, std::string appname);
void setWindowIcon(std::string path_to_img);
void putImage(std::string path_to_img, int posx, int posy, Color tint);
void destroyApp();