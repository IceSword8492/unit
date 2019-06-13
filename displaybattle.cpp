// Author: 中村宥哉
// 戦闘時の描画関数の定義

#ifndef DISPLAYBATTLE
#define DISPLAYBATTLE

namespace display
{
    void displayBattle ()
    {
        strcpy(message, "");
        printf("残り時間: %03ds                                                                               学年: %d\n%s%s\n知識: %d\n%s\n#DEBUG BATTLE (Press any key to continue...)\n",
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