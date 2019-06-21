//by Daichi Uesugi
#ifndef ENEMYACTION
#define ENEMYACTION

void enemyAction ()
{
    Enemy* enemy = getEnemy();
    isCritical();
    acttmp = false;
    bool attacked = false;
    if (enemy->charge)
    {
        tmpAttack *= 2.f;
        enemy->charge = false;
    }
    if (player.skills[1])
    {
        tmpAttack /= 2.f;
    }
    if (enemy->spact && spact[enemy->spact - 1].spact)
    {
        player.hp -= tmpAttack * spact[enemy->spact - 1].spact();
        attacked = true;
    }
    if ((!enemy->spact || acttmp) && enemy->act && act[enemy->act - 1].act)
    {
        player.hp -= tmpAttack * act[enemy->act - 1].act();
        attacked = true;
    }
    if (!enemy->spact && !enemy->act)
    {
        player.hp -= tmpAttack * enemy->stdAtk;
        attacked = true;
    }
    if (!attacked)
    {
        printf("invalid attack pattern.");
        exit(1);
    }
}

#endif