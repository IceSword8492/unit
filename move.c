//熊澤祐希
//学生の移動

// fixed by Yuya Nakamura
// added #ifndef~#endif
// fixed indent
// added if (chec...

#ifndef MOVE
#define MOVE

void move (int inputDirection)
{
    int direction = getRoom()->direction;
    bool moved = false;
    if (inputDirection & direction)
    {
        if (strcmp(getRoom()->eventName, "pickUpText") == 0 && textBooks[player.pos[0] / 2])
        {
            textBooks[player.pos[0] / 2] = false; // pickUpText()に変更予定
            addIntelligence(50);
        }
        switch (inputDirection)
        {
        case 1:
            player.pos[1]++; //右
            break;

        case 2:
            player.pos[0]++; //上
            break;

        case 4:
            player.pos[1]--; //左
            break;
        }
        moved = true;
    }
    if (moved)
    {
        // エンカウントしたか判定
        if (checkEncount())
        {
            setState(D_BATTLE);
            setCursor(0);
        }
    }
}

#endif