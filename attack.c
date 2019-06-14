// by Daichi Uesugi

#ifndef ATTACK
#define ATTACK

void attack ()
{
    enemy.hp -= tmpAttack;

    if (player.skills[0] > 0)
    {
        player.skills[0] -= 1;
    }

    if (player.skills[1] > 0)
    {
        player.skills[1] -= 1;
    }
}

#endif