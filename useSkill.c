//by Daichi Uesugi

#ifndef USESKILL
#define USESKILL

void useSkill ()
{
    switch (cursor.pos - 1)
    {
    case 0:

    player.skills[0] = 1;
    player.recast[0] = 4;
    break;

    case 1:

    player.skills[1] = 2;
    player.recast[1] = 5;
    break;

    case 2:

    player.hp += 2500;
    player.recast[2] = 2;
    break;

    case 3:
    player.recast[3] = 5;
    
    player.recast[0] -= 1;
    player.recast[1] -= 1;
    player.recast[2] -= 1;

    break;

    }
}

#endif