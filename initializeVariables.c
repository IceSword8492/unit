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
    state = 0;
    bool tbs[] = {true, true, true, true};
    memcpy(textBooks, tbs, 4);
}

#endif