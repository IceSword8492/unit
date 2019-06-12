// Author: ’†‘º—GÆ
// ƒQ[ƒ€‚Ìó‘Ô‚ğ•ÏX‚·‚éŠÖ”‚Ì’è‹`

#ifndef SETSTATE
#define SETSTATE

int setState (int s)
{
    prevState = state;
    state = s;
    return state;
}

#endif