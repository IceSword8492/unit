// Author: �����G��
// �c�莞�Ԍv�Z�֐��̒�`

#ifndef CALCREMAIN
#define CALCREMAIN

int calcRemain () // returns remain time millisec
{
    if (lose || finish != 0)
    {
        return limitTime -(finish - startTime) - debugTime;
    }
        return limitTime - (now - startTime) - debugTime;
}

#endif