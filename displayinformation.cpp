// Author: íÜë∫óGç∆
// èÓïÒï\é¶ä÷êîÇÃíËã`

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
            if (showFps)
            {
                printf("TIME: %03ds                                                                               GRADE: %d\nFPS: %02d\n", (time::calcRemain() / 1000), player.pos[0] / 2 + 1, (int)fps);
            }
            else
            {
                if (player.pos[0] % 2 == 0)
                {
                    printf("TIME: %03ds                                                                               GRADE: %d\n\n%s\n|a|b|c|d|e|\n",
                    (time::calcRemain() / 1000),
                    player.pos[0] / 2 + 1,
                    message
                    );
                }
                else if (player.pos[0] != 7)
                {
                    printf("TIME: %03ds                                                                               GRADE: %d\n\n%s\n", (time::calcRemain() / 1000), player.pos[0] / 2 + 1, "TEST");
                }
            }
        }
    }
}

#endif