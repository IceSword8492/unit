// Author: �����G��
// �O���[�o���ϐ��������֐��̒�`

#ifndef INITVARS
#define INITVARS

void initializeVariables ()
{
    tmpAttack = 0;
    win = false;
    lose = false;
    trueClear = false;
    score = 0;
    isInShop = false;
    prevState = 0;
    state = 0;
    bool tbs[] = {true, true, true, true};
    memcpy(textBooks, tbs, 4);
    Cursor tmpcsr{2};
    memcpy(&cursor, &tmpcsr, sizeof(Cursor));
    rand(); //����̃����_���l���̂Ă�
    nextGradeFlag = false;
    refreshSpeed = 33;
    enemyPop = true;
    debug = false;
    debugTime = 0;
}

#endif