// Author: 中村宥哉
// キー入力関数定義

#ifndef INPUTKEY
#define INPUTKEY

void inputKey(){
    if (kbhit())
    {
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
                if(state == D_DUNGEON)
                {
                    useItem(0);
                }
                break;
            case 'i':
            case 'I':
                if (state == D_DUNGEON)
                {
                    setState(D_ITEM);
                }
                break;
            case 13: // enter
                execute();
                break;
            case 0x1b: // esc
                if (state == D_ESC_MENU)
                {
                    setState(prevState);
                }
                else
                {
                    setState(D_ESC_MENU);
                    setCursor(0);
                }
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
}

#endif