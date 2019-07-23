// Author: �����G��
// �퓬���̕`��֐��̒�`

#ifndef DISPLAYBATTLE
#define DISPLAYBATTLE

namespace display
{
    void displayBattle ()
    {
         strcpy(message, getEnemy()->state[0] ? "�G�̏��: ����" : "");
        printf("�c�莞��: %03ds                  �w�N: %d\n%s%s\nHP: %5d / %5d           �m��: %5d\n�GHP: %5d / %5d\n             %s\n�G�i�W�[�h�����N: %d ���|�[�g�p��: %3d ������: %d\n|%s�o��|%s���|�[�g��o|%s�X�L��|%s��(�G�i�W�[�h�����N)|\n",
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
        strcpy(message, getEnemy()->state[0] ? "�G�̏��: ����" : "");
        printf("�c�莞��: %03ds                  �w�N: %d\n%s%s\nHP: %5d / %5d           �m��: %5d\n�GHP: %5d / %5d             %s\n�G�i�W�[�h�����N: %d ���|�[�g�p��: %3d ������: %d\n|%s�߂�|%s�\\�K(%d)|%s%s%s%s%s%s%s%s%s%s%s%s\n",
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
            player.pos[0] / 2 > 0 ? "���K(" : "",
            r1,
            player.pos[0] / 2 > 0 ? ")|" : "",
            player.pos[0] / 2 > 1 && cursor.pos == 3 ? ">" : " ",
            player.pos[0] / 2 > 1 ? "�[�ċz(" : "",
            r2,
            player.pos[0] / 2 > 1 ? ")|" : "",
            player.pos[0] / 2 > 2 && cursor.pos == 4 ? ">" : " ",
            player.pos[0] / 2 > 2 ? "�������K��(" : "",
            r3,
            player.pos[0] / 2 > 2 ? ")|" : ""
        );
    }
}

#endif