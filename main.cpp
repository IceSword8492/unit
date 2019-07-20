#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"

#define D_RULE       0
#define D_DUNGEON    1
#define D_BATTLE     2
#define D_SHOP       3
#define D_SKILL      4
#define D_ITEM       5
#define D_CLEAR      6
#define D_GAMEOVER   7
#define D_ESC_MENU  99

int main (int argc, const char** arv)
{
    initializeConsole();
    int counter = 0;
    while (true)
    {
        if (counter > 10)
        {
            break;
        }
        if (getch() == 'g')
        {
            counter++;
        }
        erase();
        printw("counter: %d\n", counter);
    }
    endwin();
    return 0;
}