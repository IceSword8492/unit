#ifndef BATTLE
#define BATTLE

float CRITICAL = 1.5f;


bool acttmp; // spactを実行したのちにactも実行する場合はtrueにする

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
        return 0;
    }
    
    return getEnemy()->stdAtk ;
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

    return getEnemy()->stdAtk;
}

float spact_4b ()
{
    if (getEnemy()->hp <= getEnemy()->maxHp / 2 && getEnemy()->state[1] == 0)
    {
        if (player.skills[1])
        {
            player.hp -= (player.hp/100)*99 / 2;
        }
        else
        {
            player.hp -= (player.hp/100)*99;
        }
        getEnemy()->state[1] = 1;
        sprintf(message,"割り合いダメージを受けた[press any key]");
        tmpAttack = 0;
        return 0;
    }
    if (getEnemy()->hp <= getEnemy()->maxHp / 5)
    {
        getEnemy()->hp = getEnemy()->maxHp / 2;
        sprintf(message,"HPを回復した[press any key]");
        tmpAttack = 0;
        return 0;
    }
    return getEnemy()->stdAtk;
}

float spact_last ()
{
    if (getEnemy()->hp <= getEnemy()->maxHp / 5)
    {
        getEnemy()->dmgCut = 1;
        if (getEnemy()->state[2] == 0)
        {
            sprintf(message,"攻撃が通りにくくなった");
            setState(D_DAMAGESTEP);
            getEnemy()->state[2] = 1;

        }
    }
    return 0;
}

Spact spact[] = {
    {spact_1b},
    {spact_2b},
    {spact_3b},
    {spact_4b},
    {spact_last}
};

int turn; // 現在のターン数を保持

typedef struct Act {
    float (*act)();
} Act;

float act_last ()
{
    switch (turn % 4)
    {
    case 1:
        getEnemy()->charge = true;
        sprintf(message,"攻撃の機会をうかがっている[press any key]");
        return 0;
    default:
        return getEnemy()->stdAtk;
    }
}

float act_4b ()
{
    switch (turn % 5)
    {
    case 1:
        getEnemy()->dmgCut = 2;
        sprintf(message,"守りを固めている[press any key]");
        return 0;
    case 2:
        getEnemy()->charge = true;
        sprintf(message,"攻撃の機会をうかがっている[press any key]");
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
#include "battleDefeat.c"
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
    initializeEnemies();
    turn = 0;
    setState(D_BATTLE);
    setCursor(0);
    if (getEnemy()->type == 2 || getEnemy()->type == 3)
    {
        getEnemy()->state[0] = 1;
    }
    if (getEnemy()->type == 3)
    {
        if (!player.item[2])
        {
            player.item[2] -= 1;
            player.hp = 0; // 先制攻撃
            battleDefeat();
        }
        else
        {
        
        player.item[2] -= 1;
        }
    }
}
#endif