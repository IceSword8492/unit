// Author: �����G��
// �G���J�E���g���������肷��֐��̒�`

#ifndef CHECKENCOUNT
#define CHECKENCOUNT

bool checkEncount ()
{
    return ((float)rand() / (float)RAND_MAX) < getRoom()->popProbability ? true : false;
}

#endif