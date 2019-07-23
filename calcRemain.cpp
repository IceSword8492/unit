// Author: 中村宥哉
// 残り時間計算関数の定義

#ifndef CALCREMAIN
#define CALCREMAIN

int calcRemain () // returns remain time millisec
{
    return limitTime - (now - startTime) - debugTime;
}

#endif