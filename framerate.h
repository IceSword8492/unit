// Author: �����G��
// �t���[�����[�g�֘A�̕ϐ��̏������֐��̒�`

#ifndef INITFRAMERATE
#define INITFRAMERATE

void initializeFramerate ()
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