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
        switch (direction)
        {
        case RIGHT:
            move(direction);
            break;
        case UP:
            move(direction);
            break;
        case LEFT:
            move(direction);
            break;
        }
        break;
    }
}

#endif