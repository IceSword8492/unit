// Author: 中村宥哉
// FPS計算及び描画処理関数呼び出し用関数の定義

#ifndef CALCFPS
#define CALCFPS

void calcFps ()
{
    now = timeGetTime();
    if (now - prevTime >= 33)
    {
        prevTime = now;
        displayInformation();
        count++;
    }
    if (now - baseTime >= 1000)
    {
        fps = (float)(count * 1000) / (float)(now - baseTime);
        baseTime = now;
        count = 0;
    }
}

#endif