//ƒQ[ƒ€‚ÌŸ—˜ˆ—by‹g‰ªŒÖ‘¾˜Y
// fixed by Yuya Nakamura
// added #ifndef~#endif

#ifndef GAMECLEAR
#define GAMECLEAR

void gameClear(){
    win = true;
    // ˆÈ‰º‚ÌAuthor ’†‘º—GÆ
    score = getScore();
    saveScore();
    updateScores();
    setState(D_CLEAR);
    setCursor(0);
}

#endif