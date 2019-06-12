// Author: 中村宥哉
// include順の関係で先に定義する必要のある変数類の定義

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