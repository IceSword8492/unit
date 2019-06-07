#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void pickUpText(){}
void goShop(){}
void useItem(){}

#include "room.h"
#include "enemy.h"
#include "student.h"
#include "variables.h"
#include "framerate.h"
#include "gameOver.c"
#include "gameClear.c"
#include "initializedungeon.c"
#include "addMoney.c"
#include "displayRule.cpp"
#include "move.c"
#include "inputDirection.c"
#include "inputKey.c"
#include "initializeStudent.c"
#include "initializeEnemies.c"
#include "addIntelligence.c"
#include "initializeVariables.c"
#include "calcRemain.cpp"
#include "displayinformation.cpp"
#include "calcFramerate.cpp"

int main (int argc, const char** argv)
{
    initializeVariables();
    initializeDungeon();
    initializeEnemies();
    time::framerateInitialization();
    for (;;)
    {
        time::calcFps();
        switch (state)
        {
        case 0:
            if (kbhit())
            {
                getch();
                state = 1;
            }
            break;
        case 1:
            if (kbhit())
            {
                inputKey(getch());
            }
        }
    }

    forceexit:;
    return 0;
}