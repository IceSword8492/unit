// Author: ’†‘º—GÆ
// FPSŒvŽZŠÖ”‚Ì’è‹`

#ifndef CALCFPS
#define CALCFPS

void calcFps ()
{
    now = timeGetTime();
    if (now - prevTime >= 33)
    {
        prevTime = now;
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