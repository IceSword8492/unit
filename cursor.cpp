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
    case D_SHOP:
        switch (direction)
        {
        case 0b100:
            if (cursor.pos != 0)
            {
                cursor.pos--;
            }
            break;
        case 0b001:
            if (cursor.pos != (player.pos[0] / 2 == 3 ? 3 : 2))
            {
                cursor.pos++;
            }
        }
        break;
    case D_ESC_MENU:
        cursor.pos ^= 1;
        break;
    }
}

#endif