//熊澤祐希
//ダメージ計算

#ifndef DAMAGE
#define DAMAGE

void damage ()
{
    player.atk += (float)player.Intelligence;
    player.skill[0]--;
    if(player.skill[0] < 0)
    {
        player.slikk[0] = 0;
    }
}

#endif