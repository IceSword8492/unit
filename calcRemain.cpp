// Author: �����G��
// �c�莞�Ԍv�Z�֐��̒�`

#ifndef CALCREMAIN
#define CALCREMAIN

namespace time
{
    int calcRemain () // returns remain time millisec
    {
        return limitTime - (now - startTime);
    }
}

#endif