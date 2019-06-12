// Author: 中村宥哉
// 表示用メッセージ作成関数

#ifndef CREATEMESSAGE
#define CREATEMESSAGE

void createMessage ()
{
    if (getRoom()->direction & 0b010 && player.pos[0] % 2 == 0 && player.pos[0] != 6 && state == D_DUNGEON)
    {
        strcpy(message, "進級試験を受験できます (w key)");
    }
    else if (strcmp(getRoom()->eventName, "pickUpText") == 0 && textBooks[player.pos[1] / 2])
    {
        strcpy(message, "教科書を発見しました (知識 +50)");
    }
    else
    {
        strcpy(message, "");
    }
}

#endif