// Author: íÜë∫óGç∆
// ÉLÅ[ì¸óÕä÷êîíËã`

#ifndef INPUTKEY
#define INPUTKEY

void inputKey(){
    char key;
    key = getch();
    if (key != 0xffffffe0)
    {
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
    else
    {
        switch (key = getch())
        {
        case 0x48:
            moveCursor(UP);
            break;
        case 0x4b:
            moveCursor(LEFT);
            break;
        case 0x4d:
            moveCursor(RIGHT);
            break;
        }
    }
}

#endif