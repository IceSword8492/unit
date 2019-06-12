// Author: 中村宥哉
// フレームレート関連の変数の初期化関数の定義

#ifndef INITFRAMERATE
#define INITFRAMERATE

void framerateInitialization ()
{
    count = 0;
    now = timeGetTime();
    baseTime = now;
    prevTime = now;
    startTime = now;
    limitTime = LIMIT_TIME;
    fps = .0f;
}

#endif