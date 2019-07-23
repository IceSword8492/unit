//ゲームの勝利処理by吉岡誇太郎
// fixed by Yuya Nakamura
// added #ifndef~#endif

#ifndef GAMECLEAR
#define GAMECLEAR

void gameClear(){
    win = true;
    // 以下のAuthor 中村宥哉
    score = getScore();
    saveScore();
    updateScores();
    setState(D_CLEAR);
    setCursor(0);
}

#endif