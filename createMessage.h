// Author: �����G��
// �\���p���b�Z�[�W�쐬�֐�

#ifndef CREATEMESSAGE
#define CREATEMESSAGE

void createMessage ()
{
    if (state == D_BATTLE)
    {
        strcpy(message, "");
    }
    else if (getRoom()->direction & 0b010 && player.pos[0] % 2 == 0 && player.pos[0] != 6 && state == D_DUNGEON)
    {
        strcpy(message, "�i���������󌱂ł��܂� (w key)  (�\\���Ȓm���ʂ��K�v�ƂȂ�܂�)");
    }
    else if (getRoom()->direction & 0b010 && player.pos[0] == 6 && state == D_DUNGEON)
    {
        strcpy(message, "���Ǝ������󌱂ł��܂� (w key)");
    }
    else if ( (player.pos[0] == 7) && (player.pos[1] == 2))
    {
        strcpy(message, "����(�Q�[���I��{a key} �A�E�ʐ�(Ex�X�e�[�W{d key}))");
    }
    else if ( (player.pos[0] == 7) && (player.pos[1] == 3))
    {
        strcpy(message, "�ʐڂ��I���܂���(�Q�[���I��:ctrl+c)");
    }
    else if (strcmp(getRoom()->eventName, "pickUpText") == 0 && textBooks[player.pos[0] / 2])
    {
        strcpy(message, "���ȏ��𔭌����܂��� (�m�� +50)");
    }
    else
    {
        strcpy(message, "");
    }
}

#endif