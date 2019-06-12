#ifndef DISPLAYESCMENU
#define DISPLAYESCMENU

void displayEscMenu ()
{
    printf("Menu\nTime: %03ds (Timer is still running.)\n\n|%sResume|%sQuit|\n", (calcRemain() / 1000), cursor.pos == 0 ? ">" : " ", cursor.pos == 1 ? ">" : " ");
}

#endif