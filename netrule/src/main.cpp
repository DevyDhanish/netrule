#include "../include/app.h"
#include "../include/config.h"
#include "../resource.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../include/raylib.h"

#if defined(_WIN32)           
#define NOGDI          
#define NOUSER           
#endif

#include <Windows.h>

#if defined(_WIN32)          
#undef near
#undef far
#endif

int main()
{
    initApp(400, 250, "NetRules");
    setWindowIcon(APP_TITLE_ICON);

    std::system("C:\\Users\\dannn\\AppData\\Local\\Programs\\Python\\Python312\\pythonw.exe C:\\Users\\dannn\\developer\\netrule\\netrule\\build\\main.py");

    double speed = 0;

    std::ifstream logfile;
    logfile.open("log.txt");
    
    std::string line;
    char buffer[250];
    if (logfile.is_open())
    {
        std::getline(logfile, line);
    }

    speed = std::stod(line);

    logfile.close();

    sprintf_s(buffer, "Speed : %s", line.c_str());

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(APP_BACKGROUND);
        putImage(APP_BANNER, 0, 0, WHITE);
        DrawText(buffer, 0, 50, 20, WHITE);
        EndDrawing();
    }

    destroyApp();

    return 0;
}