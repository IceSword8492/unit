//�F�V�S��
//�N���e�B�J������

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