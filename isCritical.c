//熊澤祐希
//クリティカル判定

#ifndef ISCRITICAL
#define ISCRITICAL

int criticalWeight = 6;

void isCritical ()
{
    int s = rand() % criticalWeight;
    if (!s)
    {
        tmpAttack = CRITICAL;
    }
    else
    {
        tmpAttack = 1;
    }
}

#endif