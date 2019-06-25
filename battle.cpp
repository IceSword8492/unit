#ifndef BATTLE
#define BATTLE

float CRITICAL = 1.5f;


bool acttmp; // spact?øΩ?øΩ?øΩ?øΩ?øΩs?øΩ?øΩ?øΩ?øΩ?øΩÃÇÔøΩ?øΩ?øΩact?øΩ?øΩ?øΩ?øΩ?øΩs?øΩ?øΩ?øΩ?øΩÍç??øΩ?øΩtrue?øΩ…ÇÔøΩ?øΩ?øΩ

Enemy* getEnemy ()
{
    return &enemies[player.pos[0] != 7 ? player.pos[0] : player.pos[1] == 2 ? 7 : 8];
}

typedef struct Spact {
    float (*spact)();
} Spact;

float spact_1b ()
{
    if (getEnemy()->hp <= getEnemy()->maxHp / 2)
    {
        return 1.5*getEnemy()->stdAtk;
    }
    return getEnemy()->stdAtk;
}

float spact_2b ()
{
    if(getEnemy()->hp <= getEnemy()->maxHp / 4)
    {
        tmpAttack *= 1.5;
    }
    if(getEnemy()->hp <= getEnemy()->maxHp / 10)
    {
        getEnemy()->hp  += getEnemy()->maxHp / 5;
    }
    return 0;
}

float spact_3b ()
{
     if(getEnemy()->hp <= getEnemy()->maxHp / 4)
    {
        getEnemy()->dmgCut = 1 ;
    }

    if(getEnemy()->hp <= 3000)
    {
        return getEnemy()->stdAtk * 2;
    }

    return 0;
}

float spact_4b ()
{
    if (getEnemy()->hp <= getEnemy()->maxHp / 2 && getEnemy()->state[0] == 0)
    {
        player.hp -= (player.hp/100)*99;
        getEnemy()->state[0] = 1;
        return 0;
    }
        

    if (getEnemy()->hp <= getEnemy()->maxHp / 5)
    {
        getEnemy()->hp = getEnemy()->maxHp / 2;
        return 0;
    }
    acttmp = true;
    return 0;
}

float spact_last ()
{
    if (getEnemy()->hp <= getEnemy()->maxHp / 5)
    {
        getEnemy()->dmgCut = 1;
    }
    acttmp = true;
    return 0;
}

Spact spact[] = {
    {spact_1b},
    {spact_2b},
    {spact_3b},
    {spact_4b},
    {spact_last}
};

int turn; // ?øΩ?øΩ?øΩ›ÇÃÉ^?øΩ[?øΩ?øΩ?øΩ?øΩ?øΩ?øΩ€éÔøΩ

typedef struct Act {
    float (*act)();
} Act;

float act_4b ()
{
    switch (turn % 4)
    {
    case 1:
        getEnemy()->charge = true;
        return 0;
    default:
        return getEnemy()->stdAtk;
    }
}

float act_last ()
{
    switch (turn % 5)
    {
    case 1:
        getEnemy()->dmgCut = 2;
        return 0;
    case 2:
        getEnemy()->charge = true;
        return 0;
    default:
        return getEnemy()->stdAtk;
    }
}

Act act[] = {
    {act_4b},
    {act_last}
};




#include "useItem.c"
#include "useSkill.c"
#include "damage.c"
#include "attack.c"
#include "isCritical.c"
#include "battleVictory.c"
#include "enemyaction.c"


void updateSkillsRecastTurn ()
{
    if (player.skills[0] > 0)
        player.skills[0] -= 1;
    if (player.skills[1] > 0)
        player.skills[1] -= 1;
    if (player.recast[0] > 0)
        player.recast[0] -= 1;
    if (player.recast[1] > 0)
        player.recast[1] -= 1;
    if (player.recast[2] > 0)
        player.recast[2] -= 1;
    if (player.recast[3] > 0)
        player.recast[3] -= 1;
}

void battleBegin ()
{
    turn = 0;
    setState(D_BATTLE);
    setCursor(0);
    if (getEnemy()->type == 3)
    {
        if (!player.item[2])
        {
            player.hp = 0; // ?øΩÊêß?øΩU?øΩ?øΩ
        }
    }
}
#endif