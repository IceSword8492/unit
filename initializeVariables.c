// Author: 中村宥哉
// グローバル変数初期化関数の定義

#ifndef INITVARS
#define INITVARS

void initializeVariables ()
{
    tmpAttack = 0;
    win = false;
    lose = false;
    trueClear = false;
    score = 0;
    isInShop = false;
    state = 0;
    bool tbs[] = {true, true, true, true};
    memcpy(textBooks, tbs, 4);
    Cursor tmpcsr = {&tmpcsr, 2};
    memcpy(&cursor, &tmpcsr, sizeof(Cursor));
    rand(); //初回のランダム値を捨てる
    nextGradeFlag = false;
}

#endif