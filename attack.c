// by Daichi Uesugi

#ifndef ATTACK
#define ATTACK

void attack ()
{
    Enemy* enemy = &enemies[player.pos[0] != 7 ? player.pos[0] : player.pos[1] == 2 ? 7 : 8];
    enemy->hp -= tmpAttack;
}

#endif