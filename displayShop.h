// Author: �����G��
// �w���`��֐���`

#ifndef DISPLAYSHOP
#define DISPLAYSHOP

void displayShop ()
{
    printf("�c�莞��: %03ds                                                                               �w�N: %d\n%s%s\n�m��: %d\n%s\n#DEBUG SHOP (Press any key to continue...)\n",
        (calcRemain() / 1000),
        player.pos[0] / 2 + 1,
        showFps ? "FPS: " : "",
        showFps ? fpsString : "",
        player.intelligence,
        message
    );
}

#endif