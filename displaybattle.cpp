// Author: ’†‘º—GÆ
// í“¬‚Ì•`‰æŠÖ”‚Ì’è‹`

#ifndef DISPLAYBATTLE
#define DISPLAYBATTLE

namespace display
{
    void displayBattle ()
    {
        strcpy(message, "");
        printf("TIME: %03ds                                                                               GRADE: %d\n\n%s\n#debug BATTLE\n",
            (calcRemain() / 1000),
            player.pos[0] / 2 + 1,
            message
        );
    }
}

#endif