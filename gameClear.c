//Q[ÌbygªÖ¾Y
// fixed by Yuya Nakamura
// added #ifndef~#endif

#ifndef GAMECLEAR
#define GAMECLEAR

void gameClear(){
    win=true;
    saveScore();
    updateScores();
}

#endif