//FāVSó
//NeBJŧč

#ifndef ISCRITICAL
#define ISCRITICAL

int criticalWeight = 6;

void isCritical ()
{
    int s = rand() % criticalWeight;
    if (s == 1)
    {
        tmpAttack = CRITICAL;
    }else{
        tmpAttack = 1;
    }
}

#endif