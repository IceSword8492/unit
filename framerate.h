#ifndef INITFRAMERATE
#define INITFRAMERATE

void framerateInitialization ()
{
    count = 0;
    now = timeGetTime();
    baseTime = now;
    prevTime = now;
    startTime = now;
    limitTime = now + LIMIT_TIME;
    fps = .0f;
}

#endif