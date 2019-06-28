#include <ios>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <signal.h>

#define D_RULE       0
#define D_DUNGEON    1
#define D_BATTLE     2
#define D_SHOP       3
#define D_SKILL      4
#define D_ITEM       5
#define D_ESC_MENU  99

#include "headers.h"

#pragma comment(lib, "winmm.lib")

using namespace display;


int main (int argc, const char** argv)
{
    srand(time(NULL));
    initializeVariables();
    initializeDungeon();
    initializeEnemies();
    initializeStudent();
    initializeSettings(argc, argv);
    initializeShops();
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
            initializeConsole();
            break;
        case D_DUNGEON:
            setCursor(player.pos[1]);
            inputKey();
            break;
        case D_BATTLE:
            inputKey();
            break;
        case D_SKILL:
            inputKey();
            break;
        case D_SHOP:
            inputKey();
            break;
        case D_ITEM:
            if (kbhit())
            {
                getch();
                setState(prevState);
            }
            break;
        case D_ESC_MENU:
            inputKey();
            break;
        }
        if (lose)
        {
            safeExit(0); // #DEBUG
        }
    }

    forceexit:;
    safeExit(0);
}