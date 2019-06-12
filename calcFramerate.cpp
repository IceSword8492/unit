// Author: ’†‘º—GÆ
// FPSŒvŽZŠÖ”‚Ì’è‹`
// displayInformationŒÄ‚Ño‚µ‚ÌŠÖŒW‚ÅŠÖ”–¼•ÏX (calcFps -> controlFps)

#ifndef CALCFPS
#define CALCFPS

using namespace display;

void controlFps ()
{
    now = timeGetTime();
    if (now - prevTime >= 33)
    {
        displayInformation();
        prevTime = now;
        count++;
    }
    if (now - prevTime == 32)
    {
        cls();
    }
    if (now - baseTime >= 1000)
    {
        fps = (float)(count * 1000) / (float)(now - baseTime);
        baseTime = now;
        count = 0;
    }
}

#endif