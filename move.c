//ŒFàV—SŠó
//Šw¶‚ÌˆÚ“®

// fixed by Yuya Nakamura
// added #ifndef~#endif
// fixed indent

#ifndef MOVE
#define MOVE

void move (int inputDirection)
{
    int direction = dungeon[player.pos[0]][player.pos[1]].direction;
    if (inputDirection & direction)
    {
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
    }
    
}

#endif