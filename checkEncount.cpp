// Author: �����G��
// �G���J�E���g���������肷��֐��̒�`

#ifndef CHECKENCOUNT
#define CHECKENCOUNT

bool checkEncount () // nextGradeFlag��false && �m��
{
    return (((float)rand() / (float)RAND_MAX) < getRoom()->popProbability) && !nextGradeFlag ? true : false;
}

#endif