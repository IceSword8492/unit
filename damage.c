//吉岡誇太郎
//ダメージ計算
#ifndef DAMAGE
#define DAMAGE
#define NORMAL_ATTACK 0
#define REPORT_ATTACK 1
void damage(int a)
{
    Enemy enemy = *getEnemy();
    switch (a)
    {
    case NORMAL_ATTACK:
        tmpAttack *= player.atk;
        break;
    case REPORT_ATTACK:
        tmpAttack *= player.atk + player.intelligence;
        break;
    }
    if (player.skills[0])
    {
        tmpAttack *= 2.5;
    }
    if (enemy.dmgCut)
    {
        tmpAttack /= 2;
        enemy.dmgCut--;
    }
}

#endif