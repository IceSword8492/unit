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
            goto a;
        }
        battleVictory();
        res = true;
    }
    a:;
    return res;
}

#endif