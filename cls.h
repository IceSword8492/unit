#ifndef CLS
#define CLS

#define CLS_SPACE ((WORD)(0x20))
#define CLS_COLOR ((WORD)(0x0f))

void cls()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi = {0};
    COORD pos = {0};
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwCharsWritten;
    GetConsoleScreenBufferInfo(hStdout, &csbi);
    FillConsoleOutputCharacter(hStdout, CLS_SPACE, (csbi.dwSize.X * csbi.dwSize.Y), pos, &dwCharsWritten);
    FillConsoleOutputAttribute(hStdout, CLS_COLOR, (csbi.dwSize.X * csbi.dwSize.Y), pos, &dwCharsWritten);
    SetConsoleCursorPosition(hStdout, pos);
}

#endif