// Author: ’†‘º—GÆ
// c‚èŠÔŒvZŠÖ”‚Ì’è‹`

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