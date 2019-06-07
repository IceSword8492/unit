// Author: ’†‘º—GÆ
// î•ñ•\¦ŠÖ”‚Ì’è‹`

#ifndef DISPLAYINFORMATION
#define DISPLAYINFORMATION

namespace display
{
    void displayInformation ()
    {
        switch (state)
        {
        case 0:
            displayRule();
            break;
        case 1:
            printf("TIME: %ds                                                                               GRADE: %d\nFPS: %02d\n", (time::calcRemain() / 1000), player.pos[0] / 2 + 1, (int)fps);
        }
    }
}

#endif