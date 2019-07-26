// by Daichi Uesugi

#ifndef ATTACK
#define ATTACK

bool attack () // void -> bool by Yuya Nakamura
{
    Enemy* enemy = getEnemy();
    enemy->hp -= tmpAttack;
    bool res = false;
    if (enemy->hp <= .0)
    {
        if (enemy->state[0])
        {
            enemy->hp = enemy->maxHp / 2;
            enemy->state[0] = 0;
            goto a;
        }
        battleVictory();
        res = true;
    }
    a:;
    if(enemy->hp <= enemy->maxHp / 5 && enemy->state[0])
    {
        enemy->state[0] = 0;
    }
    return res;
}

#endif