// Author: íÜë∫óGç∆
// Define student struct and constructor

#ifndef STUDENT
#define STUDENT

#define STUDENT_POS {0, 2}
#define STUDENT_MAX_HP 10000.f
#define STUDENT_HP 10000.f
#define STUDENT_ATK 100.f
#define STUDENT_INT 0
#define STUDENT_MONEY 1000
#define STUDENT_ITEM {0, 0, 0} // energy, paper, es
#define STUDENT_RECAST {0, 0, 0, 0}
#define STUDENT_SKILLS {0, 0}

typedef struct Student {
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
    int getGradeId ()
    {
        return pos[0] / 2;
    }
    int getGrade ()
    {
        return getGradeId() + 1;
    }
} Student;

Student new_Student (const char* name)
{
    Student s = {
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

#endif