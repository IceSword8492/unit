// Author:中村宥哉
// 決定キー押下時実行関数の定義

#ifndef EXECUTE
#define EXECUTE

void execute ()
{
    switch (state)
    {
    case D_ESC_MENU:
        switch (cursor.pos)
        {
        case 0:
            setState(prevState);
            break;
        case 1:
            safeExit(0);
            break;
        }
        break;
    }
}

#endif