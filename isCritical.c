//�F�V�S��
//�N���e�B�J������

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