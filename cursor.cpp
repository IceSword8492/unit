// Author: 中村宥哉
// カーソル関係の定義

#ifndef CURSOR
#define CURSOR

void setCursor (int pos)
{
    cursor.pos = pos;
}

void moveCursor (int direction)
{
    switch (state)
    {
    case D_DUNGEON:
        move(direction);
        break;
    case D_ESC_MENU:
        cursor.pos ^= 1;
        break;
    }
}

#endif