// Author: ºGÆ
// í¬Ì`æÖÌè`

#ifndef DISPLAYBATTLE
#define DISPLAYBATTLE

namespace display
{
    void displayBattle ()
    {
        //strcpy(message, getEnemy()->state[0] ? "GÌóÔ: ª«" : "");
        strcpy(message," ");
        printf("cèÔ: %03ds                  wN: %d\n%s%s\nHP: %5d / %5d           m¯: %5d\nGHP: %5d / %5d                %s\n%s\nGiW[hN: %d |[gp: %3d ð: %d\n|%soÈ|%s|[gño|%sXL|%sñ(GiW[hN)|\n",
            (calcRemain() / 1000),
            player.pos[0] / 2 + 1,
            showFps ? "FPS: " : "",
            showFps ? fpsString : "",
            (int) player.hp,
            (int) player.maxHp,
            player.intelligence,
            (int) getEnemy()->hp,
            (int) getEnemy()->maxHp,
            getEnemy()->state[0] == 1 ? "ª«" : "",
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
        //strcpy(message, getEnemy()->state[0] ? "GÌóÔ: ª«" : "");
        strcpy(message," ");
        printf("cèÔ: %03ds                  wN: %d\n%s%s\nHP: %5d / %5d           m¯: %5d\nGHP: %5d / %5d                %s\n%s\nGiW[hN: %d |[gp: %3d ð: %d\n|%sßé|%s\\K(%d)|%s%s%s%s%s%s%s%s%s%s%s%s\n",
            (calcRemain() / 1000),
            player.pos[0] / 2 + 1,
            showFps ? "FPS: " : "",
            showFps ? fpsString : "",
            (int) player.hp,
            (int) player.maxHp,
            player.intelligence,
            (int) getEnemy()->hp,
            (int) getEnemy()->maxHp,
            getEnemy()->state[0] == 1 ? "ª«" : "",
            message,
            player.item[0],
            player.item[1],
            player.item[2],
            cursor.pos == 0 ? ">" : " ",
            cursor.pos == 1 ? ">" : " ",
            player.recast[0],
            player.pos[0] / 2 > 0 && cursor.pos == 2 ? ">" : " ",
            player.pos[0] / 2 > 0 ? "K(" : "",
            r1,
            player.pos[0] / 2 > 0 ? ")|" : "",
            player.pos[0] / 2 > 1 && cursor.pos == 3 ? ">" : " ",
            player.pos[0] / 2 > 1 ? "[Äz(" : "",
            r2,
            player.pos[0] / 2 > 1 ? ")|" : "",
            player.pos[0] / 2 > 2 && cursor.pos == 4 ? ">" : " ",
            player.pos[0] / 2 > 2 ? "¤ºKâ(" : "",
            r3,
            player.pos[0] / 2 > 2 ? ")|" : ""
        );
    }
}

#endif