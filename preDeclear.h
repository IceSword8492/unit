// Author: �����G��
// include���̊֌W�Ő�ɒ�`����K�v�̂���ϐ��ނ̒�`

#ifndef PREDECLEAR
#define PREDECLEAR

#define LEFT 4
#define UP 2
#define RIGHT 1

extern int state;
extern Student player;
typedef struct Cursor {
    struct Cursor* self;
    int pos;
} Cursor;
extern struct Cursor cursor;
void setCursor(int);
#endif