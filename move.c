//ŒFàV—SŠó
//Šw¶‚ÌˆÚ“®

// fixed by Yuya Nakamura
// added #ifndef~#endif
// fixed indent
// added if (moved...

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
            pickUpText();
        }
        switch (inputDirection)
        {
        case 1:
            player.pos[1]++; //‰E
            break;

        case 2:
            player.pos[0]++; //ã
            break;

        case 4:
            player.pos[1]--; //¶
            break;
        }
        moved = true;
    }
    if (moved)
    {
        // ƒGƒ“ƒJƒEƒ“ƒg‚µ‚½‚©”»’è
        if (checkEncount() && enemyPop)
        {
            setState(D_BATTLE);
            setCursor(0);
        }
        if (strcmp(getRoom()->eventName, "goShop") == 0)
        {
            setState(D_SHOP);
            setCursor(0);
        }
    }
}

#endif