// Author: 中村宥哉
// 残り時間計算関数の定義

#ifndef CALCREMAIN
#define CALCREMAIN

int calcRemain () // returns remain time millisec
{
    if (lose || finish != 0)
    {
        return limitTime -(finish - startTime) - debugTime;
    }
        return limitTime - (now - startTime) - debugTime;
}

#endif