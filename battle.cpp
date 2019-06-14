#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define D_RULE       0
#define D_DUNGEON    1
#define D_BATTLE     2
#define D_SHOP       3
#define D_ESC_MENU  99

#define STUDENT_POS {0, 2}
#define STUDENT_MAX_HP 10000.f
#define STUDENT_HP 10000.f
#define STUDENT_ATK 100.f
#define STUDENT_INT 0
#define STUDENT_MONEY 1000
#define STUDENT_ITEM {0, 0, 0} // energy, paper, es
#define STUDENT_RECAST {4, 5, 2, 5}
#define STUDENT_SKILLS {0, 0}

int state, prevState;

void setState (int s)
{
    prevState = state;
    state = s;
}

typedef struct Student {
    struct Student* self;
    char name[256];
    int pos[2];
    float maxHp;
    float hp;
    float atk;
    int intelligence;
    int money;
    int item[3];
    int recast[4];
    int skills[2];
} Student;

Student new_Student (const char* name)
{
    Student s = {
        &s,
        "",
        STUDENT_POS,
        STUDENT_MAX_HP,
        STUDENT_HP,
        STUDENT_ATK,
        STUDENT_INT,
        STUDENT_MONEY,
        STUDENT_ITEM,
        STUDENT_RECAST,
        STUDENT_SKILLS
    };
    strcpy(s.name, name);
    return s;
}

typedef struct Cursor {
    int pos;
} Cursor;

Cursor cursor;
Student player;

#include "useItem.c"
#include "useSkill.c"

int main (int argc, const char** argv)
{
    cursor.pos = 0;
    player = new_Student("TestStudent");
    player.intelligence = 300;
    player.item[0] = 2;
    player.item[1] = 100;
    player.item[2] = 1;
    state = D_BATTLE;
    srand(time(NULL));
    rand();
    for (;;)
    {
        if (kbhit())
        {
            switch (getch())
            {
            case 'd':
                cursor.pos++;
                break;
            case 'a':
                if (cursor.pos > 0) cursor.pos--;
                break;
            case '.':
                state++;
                break;
            case ',':
                state--;
                break;
            }
        }
        printf("---\n名前: %s\n知識: %d\nCursor: %d\nstate: %d\nHP: %5d, 知識: %4d\nエナジードリンク: %2d本, レポート用紙: %3d枚, 履歴書: %1d枚\n",
            player.name,
            player.intelligence,
            cursor.pos,
            state,
            (int)player.hp,
            player.intelligence,
            player.item[0],
            player.item[1],
            player.item[2]
        );
    }
    return 0;
}