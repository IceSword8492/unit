// Author: 中村宥哉
// 表示用メッセージ作成関数

#ifndef CREATEMESSAGE
#define CREATEMESSAGE

void createMessage ()
{
    if (getRoom()->direction & 0b010 && player.pos[0] % 2 == 0 && player.pos[0] != 6 && state == D_DUNGEON)
    {
        strcpy(message, "進級試験を受験できます(w key)");
    }
    else
    {
        strcpy(message, "");
    }
}

#endif