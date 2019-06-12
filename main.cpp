#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <signal.h>

void pickUpText(){}

#define D_RULE       0
#define D_DUNGEON    1
#define D_BATTLE     2
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
    framerateInitialization();
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
            if (kbhit())
            {
                inputKey(getch());
            }
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
            if (kbhit())
            {
                inputKey(getch());
            }
            break;
        }
    }

    forceexit:;
    safeexit(0);
}