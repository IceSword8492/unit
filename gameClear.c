//�Q�[���̏�������by�g���֑��Y
// fixed by Yuya Nakamura
// added #ifndef~#endif

#ifndef GAMECLEAR
#define GAMECLEAR

void gameClear(){
    win = true;
    // �ȉ���Author �����G��
    score = getScore();
    saveScore();
    updateScores();
    setState(D_CLEAR);
    setCursor(0);
}

#endif