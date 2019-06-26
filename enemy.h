// Author: �����G��
// Define enemy struct and constructor

#ifndef ENEMY
#define ENEMY

typedef struct Enemy
{
    int hp;             // HP
    int maxHp;          // �ő�HP
    float stdAtk;       // ��b�U����
    bool charge;        // ���߂̗L��
    int dmgCut;         // �����̎c��^�[����
    int intelligence;   // ���炦��m����
    int type;           // ��:1, �ʏ�:2, ���{�X:3���G��:0��
    int act;            // �s�����[�`��
    int spact;          // ����s��
    int state[256];
} Enemy;

Enemy new_Enemy (int hp, int maxHp, float stdAtk, int intelligence, int type, int act, int spact)
{
    Enemy e = {
        hp,
        maxHp,
        stdAtk,
        0,
        0,
        intelligence,
        type,
        act,
        spact
    };
    return e;
}

#endif