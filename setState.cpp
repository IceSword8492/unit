// Author: 中村宥哉
// ゲームの状態を変更する関数の定義

#ifndef SETSTATE
#define SETSTATE

int setState (int s)
{
    prevState = state;
    state = s;
    return state;
}

#endif