#ifndef INITIALIZE
#define INITIALIZE

void initialize (int argc, const char** argv)
{
    s_argc = argc;
    s_argv = argv;
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

#endif