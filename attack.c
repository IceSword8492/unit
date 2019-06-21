// by Daichi Uesugi

#ifndef ATTACK
#define ATTACK

void attack ()
{
    Enemy* enemy = getEnemy();
    enemy->hp -= tmpAttack;
}

#endif