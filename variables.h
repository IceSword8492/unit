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
char fpsString[256];
float tmpAttack;      // �U���͌v�Z�p�ϐ�
bool win;           // ��������
bool lose;          // ��������
bool trueClear;     // ���{�X��|������
float score;        // �X�R�A
Student player;     // �v���C���[�ϐ�
Room dungeon[8][5]; // �_���W�����ϐ�
Enemy enemies[9];     // �G�z��
bool isInShop;      // �w���ɂ��邩
int state;          // �Q�[���̏��
int prevState;      // �ϑJ�O�̃Q�[���̏��
bool showFps;       // setting�p�ϐ�
char message[256];  // ��ʂɃ��b�Z�[�W���o�����߂̕ϐ�
Cursor cursor;      // �J�[�\���|�W�V������ێ�����ϐ�
bool textBooks[4];  // �e�K�w�̃e�L�X�g�u�b�N�擾�󋵕ێ��ϐ�
bool nextGradeFlag; // �w�N���オ�������ɃG���J�E���g���Ȃ��悤�ɂ��邽�߂̕ϐ�
int refreshSpeed;
bool enemyPop;
Shop shops[4];
Scores scores;
bool debug;
int debugTime;
int s_argc;
const char** s_argv;

#endif