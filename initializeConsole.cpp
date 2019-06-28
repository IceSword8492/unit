// Author: 中村宥哉
// コンソール関連の初期化関数及び終了関数の定義

#ifndef INITCONSOLE
#define INITCONSOLE

void safeExit(int);

void signalHandler (int signal)
{
    switch (signal)
    {
    case SIGINT: // received ctrl + C
        safeExit(0);
        break;
    }
}

void initializeConsole ()
{
    typedef void (*SignalHandlerPointer)(int);
    SignalHandlerPointer prevHandler = signal(SIGINT, signalHandler);
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hStdout, &cci);
    cci.bVisible = false;
    SetConsoleCursorInfo(hStdout, &cci);
}

void safeExit(int errnum)
{
    if (errnum >= 0)
    {
        cls();
    }
    CONSOLE_CURSOR_INFO cci;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdout, &cci);
    cci.bVisible = true;
    SetConsoleCursorInfo(hStdout, &cci);
    exit(errnum);
}

#endif