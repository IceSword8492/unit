// Author: �����G��
// �퓬���̕`��֐��̒�`

#ifndef DISPLAYBATTLE
#define DISPLAYBATTLE

namespace display
{
    void displayBattle ()
    {
        strcpy(message, "");
        printf("�c�莞��: %03ds                                                                               �w�N: %d\n%s%s\n�m��: %d\n%s\n#DEBUG BATTLE (Press any key to continue...)\n",
            (calcRemain() / 1000),
            player.pos[0] / 2 + 1,
            showFps ? "FPS: " : "",
            showFps ? fpsString : "",
            player.intelligence,
            message
        );
    }
}

#endif