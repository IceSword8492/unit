//熊澤祐希
//クリティカル判定

#ifndef ISCRITICAL
#define ISCRITICAL

void isCritical ()
{
    int s = rand() % 6;
    if (s == 1)
    {
        tmpAttack = CRITICAL;
    }else{
        tmpAttack = 1;
    }
}

#endif