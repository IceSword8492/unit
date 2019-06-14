// Author: 中村宥哉
// 購買描画関数定義

#ifndef DISPLAYSHOP
#define DISPLAYSHOP

void displayShop ()
{
    printf("残り時間: %03ds                                                                               学年: %d\n%s%s\n知識: %d\n%s\n#DEBUG SHOP (Press any key to continue...)\n",
        (calcRemain() / 1000),
        player.pos[0] / 2 + 1,
        showFps ? "FPS: " : "",
        showFps ? fpsString : "",
        player.intelligence,
        message
    );
}

#endif