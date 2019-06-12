#ifndef SETSTATE
#define SETSTATE

int setState (int s)
{
    prevState = state;
    state = s;
    return state;
}

#endif