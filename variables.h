// Author: �����G��
// �ϐ��錾

#ifndef VARIABLES
#define VARIABLES

#define LIMIT_TIME 900000

int startTime;      // �J�n����
int limitTime;      // ��������
int prevTime;       // �t���[�����[�g����p�ϐ�
int now;            // �t���[�����[�g����p�ϐ�
int baseTime;       // �t���[�����[�g����p�ϐ�
int count;          // �t���[�����[�g����p�ϐ�
float fps;          // �t���[�����[�g�ێ��ϐ�
int tmpAttack;      // �U���͌v�Z�p�ϐ�
bool win;           // ��������
bool lose;          // ��������
bool trueClear;     // ���{�X��|������
float score;        // �X�R�A
Student player;     // �v���C���[�ϐ�
Room dungeon[8][5]; // �_���W�����ϐ�
Enemy* enemies;     // �G�z��
bool isInShop;      // �w���ɂ��邩
int state;          // �Q�[���̏�� (displayinformation���Q��)

#endif