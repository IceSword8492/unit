// Author: �����G��
// FPS�v�Z�֐��̒�`
// displayInformation�Ăяo���̊֌W�Ŋ֐����ύX (calcFps -> controlFps)

#ifndef CALCFPS
#define CALCFPS

using namespace display;

void controlFps ()
{
    now = timeGetTime();
    if (now - prevTime >= refreshSpeed)
    {
        cls();
        displayInformation();
        createMessage();
        prevTime = now;
        count++;
        if (calcRemain() < 0)
        {
            gameOver();
        }
    }
    if (now - baseTime >= 1000)
    {
        fps = (float)(count * 1000) / (float)(now - baseTime);
        sprintf(fpsString, "%03d", (unsigned int)fps);
        baseTime = now;
        count = 0;
    }
}

#endif