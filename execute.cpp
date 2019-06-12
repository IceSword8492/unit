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
            safeexit(0);
            break;
        }
        break;
    }
}

#endif