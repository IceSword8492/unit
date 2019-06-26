// by Daichi Uesugi

#ifndef ATTACK
#define ATTACK

void attack ()
{
    Enemy* enemy = getEnemy();
    enemy->hp -= tmpAttack;
    if (enemy->hp <= .0)
    {
        if (enemy->state[0])
        {
            enemy->hp = 50;
            goto a;
        }
        battleVictory();
    }
    a:;
}

#endif