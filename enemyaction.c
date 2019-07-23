//by Daichi Uesugi
#ifndef ENEMYACTION
#define ENEMYACTION

void enemyAction ()
{
    Enemy* enemy = getEnemy();
    isCritical();
    acttmp = false;
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
        tmpAttack *= spact[enemy->spact -1].spact();

        if(tmpAttack == 0)
        {
            setState(D_DAMAGESTEP);
        }
        if(tmpAttack != 0)
        {
            sprintf(message,"%dダメージを受けた[press any key]",(int)tmpAttack);
            setState(D_DAMAGESTEP);
        }
    }
    if ((!enemy->spact || acttmp) && enemy->act && act[enemy->act - 1].act)
    {
        player.hp -= tmpAttack * act[enemy->act - 1].act();
        tmpAttack *= act[enemy->act - 1].act();

        if(tmpAttack == 0)
        {
            setState(D_DAMAGESTEP);
        }
        if(tmpAttack != 0)
        {
            sprintf(message,"%dダメージを受けた[press any key]",(int)tmpAttack);
            setState(D_DAMAGESTEP);
        }
    }
    if(enemy->type == 0)
    {
        player.hp -= tmpAttack * enemy->stdAtk;
        tmpAttack *= enemy->stdAtk;
        sprintf(message,"%dダメージを受けた[press any key]",(int)tmpAttack);
        setState(D_DAMAGESTEP);
    }
    if (player.hp <= .0)
    {
        battleDefeat();
    }
}

#endif