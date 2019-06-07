// Author: ºGÆ
// FPSvZyÑ`æÖÄÑoµpÖÌè`

#ifndef CALCFPS
#define CALCFPS

namespace time
{
    void calcFps ()
    {
        now = timeGetTime();
        if (now - prevTime >= 33)
        {
            prevTime = now;
            display::displayInformation();
            count++;
        }
        if (now - baseTime >= 1000)
        {
            fps = (float)(count * 1000) / (float)(now - baseTime);
            baseTime = now;
            count = 0;
        }
    }
}

#endif