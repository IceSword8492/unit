//by Daichi Uesugi
#ifndef ENEMYACTION
#define ENEMYACTION

void enemyAction ()
{
    Enemy enemy = enemies[player.pos[0] != 7 ? player.pos[0] : player.pos[1] == 2 ? 7 : 8];
    isCritical();
    if (enemy.charge)
    {
        tmpAttack *= 2.f;
    }
    if (player.skills[1])
    {
        tmpAttack /= 2.f;
    }
    player.hp -= tmpAttack * stdAttack;
}

#endif