// Author: �����G��
// �\���p���b�Z�[�W�쐬�֐�

#ifndef CREATEMESSAGE
#define CREATEMESSAGE

void createMessage ()
{
    if (getRoom()->direction & 0b010 && player.pos[0] % 2 == 0 && player.pos[0] != 6 && state == D_DUNGEON)
    {
        strcpy(message, "�i���������󌱂ł��܂�(w key)");
    }
    else
    {
        strcpy(message, "");
    }
}

#endif