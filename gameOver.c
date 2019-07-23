//ƒQ[ƒ€‚Ì”s–kˆ—by‹g‰ªŒÖ‘¾˜Y
// fixed by Yuya Nakamura
// added #ifndef~#endif

#ifndef GAMEOVER
#define GAMEOVER

void gameOver () {
    lose = true;
    // ˆÈ‰º‚ÌAuthor ’†‘º—GÆ
    score = getScore();
    saveScore();
    updateScores();
    setState(D_GAMEOVER);
    setCursor(0);
}

#endif