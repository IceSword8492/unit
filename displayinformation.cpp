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
        case D_DUNGEON:
            if (player.pos[0] % 2 == 0)
            {
                printf("�c�莞��: %03ds                  �w�N: %d\n%s%s\nHP: %5d / %5d           �m��: %5d\n������: %4d      �G�i�W�[�h�����N: %1d��\n%s\n|%s%s|%s%s%s|%s%s%s|%s%s%s|%s%s|\n",
                    (calcRemain() / 1000),
                    player.pos[0] / 2 + 1,
                    showFps ? "FPS: " : "",
                    showFps ? fpsString : "",
                    (int) player.hp,
                    (int) STUDENT_MAX_HP,
                    player.intelligence,
                    player.money,
                    player.item[0],
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
                printf("�c�莞��: %03ds                                                                               �w�N: %d\n%s%s\n�m��: %d\n%s\n|%s%s|%s%s%s|%s%s|\n",
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
        case D_SKILL:
            displaySkill();
            break;
        case D_SHOP:
            displayShop();
            break;
        case D_ITEM:
            printf("Items\n\n\t�E�G�i�W�[�h�����N(��):\t%3d��\n\t�E���|�[�g�p��:\t\t\t%3d��\n\t�E������:\t\t\t%3d��\n\nPress any key to return.\n",
                player.item[0],
                player.item[1],
                player.item[2]
            );
            break;
        case D_CLEAR:
            printf("�Q�[���N���A\n");
            break;
        case D_GAMEOVER:
            printf("�Q�[���I�[�o�[\n");
            break;
        case D_ESC_MENU:
            displayEscMenu();
            break;
        }
    }
}

#endif