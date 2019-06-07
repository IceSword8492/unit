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
#include "displayRule.c"
#include "move.c"
#include "inputDirection.c"
#include "inputKey.c"
#include "initializeStudent.c"
#include "initializeEnemies.c"
#include "addIntelligence.c"
#include "initializeVariables.c"
#include "displayinformation.c"
#include "calcFramerate.c"

int main (int argc, const char** argv)
{
    initializeVariables();
    initializeDungeon();
    framerateInitialization();
    for (;;)
    {
        calcFps();
    }
    return 0;
}