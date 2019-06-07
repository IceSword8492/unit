//熊澤祐希
//学生の移動

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
            player.pos[1]++; //右
            break;

        case 2:
            player.pos[0]++; //上
            break;

        case 4:
            player.pos[1]--; //左
            break;
        }
    }
    
}

#endif