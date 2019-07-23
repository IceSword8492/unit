//ゲームの敗北処理by吉岡誇太郎
// fixed by Yuya Nakamura
// added #ifndef~#endif

#ifndef GAMEOVER
#define GAMEOVER

void gameOver () {
    lose = true;
    // 以下のAuthor 中村宥哉
    score = getScore();
    saveScore();
    updateScores();
    setState(D_GAMEOVER);
    setCursor(0);
}

#endif