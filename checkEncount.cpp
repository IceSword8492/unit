// Author: 中村宥哉
// エンカウントしたか判定する関数の定義

#ifndef CHECKENCOUNT
#define CHECKENCOUNT

bool checkEncount () // nextGradeFlagがfalse && 確率
{
    return (((float)rand() / (float)RAND_MAX) < getRoom()->popProbability) && !nextGradeFlag ? true : false;
}

#endif