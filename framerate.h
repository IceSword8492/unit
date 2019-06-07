#ifndef INITFRAMERATE
#define INITFRAMERATE

namespace time
{
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
}

#endif