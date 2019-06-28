// Author: 中村宥哉
// 表示用メッセージ作成関数

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
        strcpy(message, "進級試験を受験できます (w key)  (十\分な知識量が必要となります)");
    }
    else if (getRoom()->direction & 0b010 && player.pos[0] == 6 && state == D_DUNGEON)
    {
        strcpy(message, "卒業試験を受験できます (w key)");
    }
    else if ( (player.pos[0] == 7) && (player.pos[1] == 2))
    {
        strcpy(message, "卒業(ゲーム終了{a key} 就職面接(Exステージ{d key}))");
    }
    else if ( (player.pos[0] == 7) && (player.pos[1] == 3))
    {
        strcpy(message, "面接を終えました(ゲーム終了:ctrl+c)");
    }
    else if (strcmp(getRoom()->eventName, "pickUpText") == 0 && textBooks[player.pos[0] / 2])
    {
        strcpy(message, "教科書を発見しました (知識 +50)");
    }
    else
    {
        strcpy(message, "");
    }
}

#endif