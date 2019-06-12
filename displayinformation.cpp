// Author: 中村宥哉
// 情報表示関数の定義

#ifndef DISPLAYINFORMATION
#define DISPLAYINFORMATION

namespace display
{
    void displayInformation ()
    {
        switch (state)
        {
        case D_DUNGEON:
            if (player.pos[0] % 2 == 0)
            {
                printf("残り時間: %03ds                                                                               学年: %d\n%s%s\n知識: %d\n%s\n|%s%s|%s%s%s|%s%s%s|%s%s%s|%s%s|\n",
                    (calcRemain() / 1000),
                    player.pos[0] / 2 + 1,
                    showFps ? "FPS: " : "",
                    showFps ? fpsString : "",
                    player.intelligence,
                    message,
                    dungeon[player.pos[0]][0].name,
                    cursor.pos == 0 ? ">" : "",
                    cursor.pos == 1 ? "<" : "",
                    dungeon[player.pos[0]][1].name,
                    cursor.pos == 1 ? ">" : "",
                    cursor.pos == 2 ? "<" : "",
                    dungeon[player.pos[0]][2].name,
                    cursor.pos == 2 ? ">" : "",
                    cursor.pos == 3 ? "<" : "",
                    dungeon[player.pos[0]][3].name,
                    cursor.pos == 3 ? ">" : "",
                    cursor.pos == 4 ? "<" : "",
                    dungeon[player.pos[0]][4].name
                );
            }
            else if (player.pos[0] != 7)
            {
                // There is nothing to display because player in this floor must be in battle or force moved to another floor.
            }
            else
            {
                printf("残り時間: %03ds                                                                               学年: %d\n%s%s\n知識: %d\n%s\n|%s%s|%s%s%s|%s%s|\n",
                    (calcRemain() / 1000),
                    player.pos[0] / 2 + 1,
                    showFps ? "FPS: " : "",
                    showFps ? fpsString : "",
                    player.intelligence,
                    message,
                    dungeon[player.pos[0]][1].name,
                    cursor.pos == 1 ? ">" : "",
                    cursor.pos == 2 ? "<" : "",
                    dungeon[player.pos[0]][2].name,
                    cursor.pos == 2 ? ">" : "",
                    cursor.pos == 3 ? "<" : "",
                    dungeon[player.pos[0]][3].name
                );
            }
            break;
        case D_BATTLE:
            displayBattle();
            break;
        case D_ESC_MENU:
            displayEscMenu();
            break;
        }
    }
}

#endif