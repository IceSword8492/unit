//�Q�[���̔s�k����by�g���֑��Y
// fixed by Yuya Nakamura
// added #ifndef~#endif

#ifndef GAMEOVER
#define GAMEOVER

void gameOver () {
    lose = true;
    // �ȉ���Author �����G��
    score = getScore();
    saveScore();
    updateScores();
    setState(D_GAMEOVER);
    setCursor(0);
}

#endif