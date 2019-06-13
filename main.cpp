#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <signal.h>

#define D_RULE       0
#define D_DUNGEON    1
#define D_BATTLE     2
#define D_SHOP       3
#define D_ESC_MENU  99

#include "headers.h"

#pragma comment(lib, "winmm.lib")

using namespace display;


int main (int argc, const char** argv)
{
    srand(time(NULL));
    initializeConsole();
    initializeVariables();
    initializeDungeon();
    initializeEnemies();
    initializeSettings(argc, argv);
    initializeStudent();
    initializeFramerate();
    for (;;)
    {
        controlFps();
        switch (state)
        {
        case D_RULE:
            displayRule();
            getch();
            setState(D_DUNGEON);
            startTime = timeGetTime();
            break;
        case D_DUNGEON:
            setCursor(player.pos[1]);
            inputKey();
            break;
        case D_BATTLE:
            if (kbhit())
            {
                if (getch()) // DEBUG
                {
                    setState(D_DUNGEON);
                }
            }
            break;
        case D_ESC_MENU:
            inputKey();
            break;
        }
    }

    forceexit:;
    safeExit(0);
}