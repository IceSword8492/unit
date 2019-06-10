#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void pickUpText(){}
void goShop(){}
void useItem(){}

#include "headers.h"

#define D_RULE 0
#define D_DUNGEON 1
#define D_ESC_MENU 99

int main (int argc, const char** argv)
{
    initializeVariables();
    initializeDungeon();
    initializeEnemies();
    initializeSettings(argc, argv);
    time::framerateInitialization();
    for (;;)
    {
        time::calcFps();
        switch (state)
        {
        case D_RULE:
            display::displayRule();
            getch();
            state = 1;
            startTime = timeGetTime();
            break;
        case D_DUNGEON:
            if (kbhit())
            {
                inputKey(getch());
            }
            display::displayInformation();
            break;
        
        case D_ESC_MENU:
            if (kbhit())
            {
                inputKey(getch());
            }
        }
    }

    forceexit:;
    return 0;
}