//FāVSó
//NeBJŧč

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