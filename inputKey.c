// Author: ’†‘º—GÆ
// ƒL[“ü—ÍŠÖ”’è‹`

#ifndef INPUTKEY
#define INPUTKEY

void inputKey(char key){
    switch (key)
    {
    case 'w':
    case 'W':
        moveCursor(UP);
        break;
    case 'a':
    case 'A':
        moveCursor(LEFT);
        break;
    case 'd':
    case 'D':
        moveCursor(RIGHT);
        break;
    case 'h':
    case 'H':
        useItem();
        break;
    case 13: // enter
        execute();
        break;
    case 0x1b: // esc
        setState(D_ESC_MENU);
        setCursor(0);
        break;
    }
}

#endif