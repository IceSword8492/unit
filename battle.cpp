#include <stdio.h>
#include <conio.h>
#include <string.h>

#define STUDENT_POS {0, 2}
#define STUDENT_MAX_HP 10000.f
#define STUDENT_HP 10000.f
#define STUDENT_ATK 100.f
#define STUDENT_INT 0
#define STUDENT_MONEY 1000
#define STUDENT_ITEM {0, 0, 0} // energy, paper, es
#define STUDENT_RECAST {4, 5, 2, 5}
#define STUDENT_SKILLS {0, 0}

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

int main (int argc, const char** argv)
{
    cursor.pos = 0;
    player = new_Student("TestStudent");
    player.intelligence = 300;
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
            }
        }
        printf("---\n���O: %s\n�m��: %d\nCursor: %d\nHP: %5d �m��: %4d\n",
            player.name,
            player.intelligence,
            cursor.pos,
            (int)player.hp,
            player.intelligence
        );
    }
    return 0;
}