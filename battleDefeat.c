//by Daichi Uesugi

#ifndef BATTLEDEFEAT
#define BATTLEDEFEAT

Enemy enemy = *getEnemy();
void battleDefeat ()
{
    if(enemy.type == 3)
    {
        win = true; 
    }
    else
    {
    lose = true;
    }
}

#endif