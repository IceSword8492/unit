// Author: �����G��
// �c�莞�Ԍv�Z�֐��̒�`

#ifndef CALCREMAIN
#define CALCREMAIN

int calcRemain () // returns remain time millisec
{
    int finish;
    if (win || lose)
    {
        if (finish == 0)
        {
            finish = now;
        }
        return limitTime -(finish - startTime) - debugTime;
    }
    return limitTime - (now - startTime) - debugTime;
}

#endif