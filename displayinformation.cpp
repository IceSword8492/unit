// Author: ’†‘º—GÆ
// î•ñ•\Ž¦ŠÖ”‚Ì’è‹`

#ifndef DISPLAYINFORMATION
#define DISPLAYINFORMATION

namespace display
{
    void displayInformation ()
    {
        switch (state)
        {
        case D_RULE:
            displayRule();
            break;
        case D_DUNGEON:
            if (showFps)
            {
                printf("TIME: %03ds                                                                               GRADE: %d\nFPS: %02d\n", (calcRemain() / 1000), player.pos[0] / 2 + 1, (int)fps);
            }
            else
            {
                if (player.pos[0] % 2 == 0)
                {
                    printf("TIME: %03ds                                                                               GRADE: %d\n\n%s\n|%s%s|%s%s%s|%s%s%s|%s%s%s|%s%s|\n",
                        (calcRemain() / 1000),
                        player.pos[0] / 2 + 1,
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
                    printf("TIME: %03ds                                                                               GRADE: %d\n\n%s\n", (calcRemain() / 1000), player.pos[0] / 2 + 1, dungeon[player.pos[0]][player.pos[1]].name);
                }
                else
                {
                    printf("TIME: %03ds                                                                               GRADE: %d\n\n%s\n|%s%s|%s%s%s|%s%s|\n",
                    (calcRemain() / 1000),
                        player.pos[0] / 2 + 1,
                        message,
                        dungeon[player.pos[0]][1].name,
                        cursor.pos == 1 ? ">" : "",
                        cursor.pos == 2 ? "<" : "",
                        dungeon[player.pos[0]][2].name,
                        cursor.pos == 2 ? ">" : "",
                        cursor.pos == 3 ? "<" : "",
                        dungeon[player.pos[0]][3].name);
                }
            }
            break;
        case D_BATTLE:
            displayBattle();
            break;
        }
    }
}

#endif