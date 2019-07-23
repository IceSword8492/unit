// Author: 中村宥哉
// 戦闘時の描画関数の定義

#ifndef DISPLAYBATTLE
#define DISPLAYBATTLE

namespace display
{
    void displayBattle ()
    {
         strcpy(message, getEnemy()->state[0] ? "敵の状態: 根性" : "");
        printf("残り時間: %03ds                  学年: %d\n%s%s\nHP: %5d / %5d           知識: %5d\n敵HP: %5d / %5d\n             %s\nエナジードリンク: %d レポート用紙: %3d 履歴書: %d\n|%s出席|%sレポート提出|%sスキル|%s回復(エナジードリンク)|\n",
            (calcRemain() / 1000),
            player.pos[0] / 2 + 1,
            showFps ? "FPS: " : "",
            showFps ? fpsString : "",
            (int) player.hp,
            (int) player.maxHp,
            player.intelligence,
            (int) getEnemy()->hp,
            (int) getEnemy()->maxHp,
            message,
            player.item[0],
            player.item[1],
            player.item[2],
            cursor.pos == 0 ? ">" : " ",
            cursor.pos == 1 ? ">" : " ",
            cursor.pos == 2 ? ">" : " ",
            cursor.pos == 3 ? ">" : " "
        );
    }
    void displaySkill ()
    {
        char r1[256] = "", r2[256] = "", r3[256] = "";
        if (player.pos[0] / 2 > 0) sprintf(r1, "%d", player.recast[1]);
        if (player.pos[0] / 2 > 1) sprintf(r2, "%d", player.recast[2]);
        if (player.pos[0] / 2 > 2) sprintf(r3, "%d", player.recast[3]);
        strcpy(message, getEnemy()->state[0] ? "敵の状態: 根性" : "");
        printf("残り時間: %03ds                  学年: %d\n%s%s\nHP: %5d / %5d           知識: %5d\n敵HP: %5d / %5d             %s\nエナジードリンク: %d レポート用紙: %3d 履歴書: %d\n|%s戻る|%s予\習(%d)|%s%s%s%s%s%s%s%s%s%s%s%s\n",
            (calcRemain() / 1000),
            player.pos[0] / 2 + 1,
            showFps ? "FPS: " : "",
            showFps ? fpsString : "",
            (int) player.hp,
            (int) player.maxHp,
            player.intelligence,
            (int) getEnemy()->hp,
            (int) getEnemy()->maxHp,
            message,
            player.item[0],
            player.item[1],
            player.item[2],
            cursor.pos == 0 ? ">" : " ",
            cursor.pos == 1 ? ">" : " ",
            player.recast[0],
            player.pos[0] / 2 > 0 && cursor.pos == 2 ? ">" : " ",
            player.pos[0] / 2 > 0 ? "復習(" : "",
            r1,
            player.pos[0] / 2 > 0 ? ")|" : "",
            player.pos[0] / 2 > 1 && cursor.pos == 3 ? ">" : " ",
            player.pos[0] / 2 > 1 ? "深呼吸(" : "",
            r2,
            player.pos[0] / 2 > 1 ? ")|" : "",
            player.pos[0] / 2 > 2 && cursor.pos == 4 ? ">" : " ",
            player.pos[0] / 2 > 2 ? "研究室訪問(" : "",
            r3,
            player.pos[0] / 2 > 2 ? ")|" : ""
        );
    }
}

#endif