#ifndef CONSOLE
#define CONSOLE

void initializeConsole ()
{
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, true);
    nodelay(stdscr, true);
    move(0, 0);
    curs_set(0);
}

void safeExit (int errnum)
{
    endwin();
    curs_set(1);
    exit(errnum);
}

#endif