// Author: �����G��
// �J�[�\���֌W�̒�`

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
    }
}

#endif