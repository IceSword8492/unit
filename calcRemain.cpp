// Author: ’†‘º—GÆ
// c‚èŠÔŒvZŠÖ”‚Ì’è‹`

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