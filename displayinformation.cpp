// Author: �����G��
// ���\���֐��̒�`

#ifndef DISPLAYINFORMATION
#define DISPLAYINFORMATION

namespace display
{
    void displayInformation ()
    {
        switch (state)
        {
        case 0:
            displayRule();
            break;
        case 1:
            if (showFps)
            {
                printf("TIME: %03ds                                                                               GRADE: %d\nFPS: %02d\n", (time::calcRemain() / 1000), player.pos[0] / 2 + 1, (int)fps);
            }
            else
            {
                if (player.pos[0] % 2 == 0)
                {
                    printf("TIME: %03ds                                                                               GRADE: %d\n\n%s\n|%s%s|%s%s%s|%s%s%s|%s%s%s|%s%s|\n",
                    (time::calcRemain() / 1000),
                        player.pos[0] / 2 + 1,
                        message,
                        dungeon[player.pos[0]][0].name,
                        player.pos[1] == 0 ? ">" : "",
                        player.pos[1] == 1 ? "<" : "",
                        dungeon[player.pos[0]][1].name,
                        player.pos[1] == 1 ? ">" : "",
                        player.pos[1] == 2 ? "<" : "",
                        dungeon[player.pos[0]][2].name,
                        player.pos[1] == 2 ? ">" : "",
                        player.pos[1] == 3 ? "<" : "",
                        dungeon[player.pos[0]][3].name,
                        player.pos[1] == 3 ? ">" : "",
                        player.pos[1] == 4 ? "<" : "",
                        dungeon[player.pos[0]][4].name
                    );
                }
                else if (player.pos[0] != 7)
                {
                    printf("TIME: %03ds                                                                               GRADE: %d\n\n%s\n", (time::calcRemain() / 1000), player.pos[0] / 2 + 1, "TEST");
                }
            }
        }
    }
}

#endif