#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define D_RULE       0
#define D_DUNGEON    1
#define D_BATTLE     2
#define D_SHOP       3
#define D_SKILL      4
#define D_ESC_MENU  99

#define STUDENT_POS {0, 2}
#define STUDENT_MAX_HP 10000.f
#define STUDENT_HP 10000.f
#define STUDENT_ATK 100.f
#define STUDENT_INT 0
#define STUDENT_MONEY 1000
#define STUDENT_ITEM {0, 0, 0} // energy, paper, es
#define STUDENT_RECAST {0, 0, 0, 0}
#define STUDENT_SKILLS {0, 0}

int state, prevState;
float tmpAttack;

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

typedef struct Enemy
{
    struct Enemy* self; // ���g
    float hp;             // HP
    float maxHp;          // �ő�HP
    float stdAtk;       // ��b�U����
    bool charge;        // ���߂̗L��
    int dmgCut;         // �����̎c��^�[����
    int intelligence;   // ���炦��m����
    int type;           // ��:1, �ʏ�:2, ���{�X:3���G��:0��
    int act;            // �s�����[�`��
    int spact;          // ����s��
} Enemy;

Enemy new_Enemy (float hp, float maxHp, float stdAtk, int intelligence, int type, int act, int spact)
{
    Enemy e = {
        &e,
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

Enemy enemies[9]; 

#define SKILL_F1B 1
#define SKILL_F2B 2
#define SKILL_F3B 3
#define SKILL_F4B 4
#define ROUTINE_F4B 5
#define SKILL_LAST 6
#define ROUTINE_LAST 7
//�G�̏�����by�g���֑��Y
void initializeEnemies(){
    Enemy e[9] = {
        new_Enemy(500,500,500,100,0,0,0),//f1z
        new_Enemy(1000,1000,1000,400,1,0,SKILL_F1B),//f1b
        new_Enemy(2000,2000,500,200,0,0,0),//f2z
        new_Enemy(4500,4500,1000,600,1,0,SKILL_F2B),//f2b
        new_Enemy(4000,4000,800,300,0,0,0),//f3z
        new_Enemy(10000,10000,1000,800,1,0,SKILL_F3B),//f3b
        new_Enemy(10000,10000,1000,450,0,0,0),//f4z
        new_Enemy(15000,15000,1000,1000,2,ROUTINE_F4B,SKILL_F4B),//f4b
        new_Enemy(50000,50000,2000,0,3,ROUTINE_LAST,SKILL_LAST),//last
    };
    memcpy(enemies, e, sizeof(e));
}


typedef struct Cursor {
    int pos;
} Cursor;

Cursor cursor;
Student player;

void addIntelligence(int intelligence){ 
    player.intelligence+=intelligence;
}


bool win;
bool lose;
bool trueClear;

typedef struct Spact {
    int (*spact)();
} Spact;

int turn; // ���݂̃^�[������ێ�

int spact_1 ()
{
    if (enemies[player.pos[0] != 7 ? player.pos[0] : player.pos[1] == 2 ? 7 : 8].hp <= enemies[player.pos[0] != 7 ? player.pos[0] : player.pos[1] == 2 ? 7 : 8].maxHp / 2)
    {
        printf("hp half\n");
        exit(0);
    }
    return 1;
}

Spact spact[] = {
    {NULL},
    {spact_1}
};

#include "useItem.c"
#include "useSkill.c"
#include "damage.c"
#include "attack.c"
#include "isCritical.c"
#include "battleVictory.c"
#include "enemyaction.c"

void setCursor (int pos)
{
    cursor.pos = pos;
}

void execute ()
{
    switch (state)
    {
    case D_BATTLE:
        isCritical();
        switch (cursor.pos)
        {
        case 0:
            damage(0);
            attack();
            enemyAction();
            break;
        case 1:
            if (player.item[1])
            {
                player.item[1]--;
                damage(1);
                attack();
                enemyAction();
            }
            break;
        case 2:
            setState(D_SKILL);
            setCursor(0);
            break;
        }
        
        if (player.skills[0] > 0)
            player.skills[0] -= 1;
        if (player.skills[1] > 0)
            player.skills[1] -= 1;
        if (player.recast[0] > 0)
            player.recast[0] -= 1;
        if (player.recast[1] > 0)
            player.recast[1] -= 1;
        if (player.recast[2] > 0)
            player.recast[2] -= 1;
        if (player.recast[3] > 0)
            player.recast[3] -= 1;
        break;
    case D_SKILL:
        if (cursor.pos <= player.pos[0] / 2 + 1 && !player.recast[cursor.pos])
        {
            useSkill();
            setState(D_BATTLE);
            enemyAction();
            setCursor(0);
        }
        break;
    }
}

int main (int argc, const char** argv)
{
    win = false;
    lose = false;
    trueClear = false;
    cursor.pos = 0;
    player = new_Student("TestStudent");
    player.intelligence = 300;
    player.item[0] = 2;
    player.item[1] = 100;
    player.item[2] = 1;
    state = D_BATTLE;
    srand(time(NULL));
    initializeEnemies();
    rand();
    tmpAttack = 0;
    for (;;)
    {
        switch (state)
        {
        case D_DUNGEON:
            player.pos[1] = cursor.pos;
            break;
        }
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
            case 'w':
                player.pos[0]++;
                break;
            case '.':
                state++;
                break;
            case ',':
                state--;
                break;
            case 13:
                execute();
                break;
            }
        }
        printf("---\n���O: %s\n�m��: %d\npos[0]: %d, pos[1]: %d\nCursor: %d\nstate: %d\nHP: %5d, �m��: %4d\n�G�i�W�[�h�����N: %2d�{, ���|�[�g�p��: %3d��, ������: %1d��\n|%s�o�� |%s���|�[�g��o |%s�X�L�� |%s�A�C�e�� |\n|%s�\\�K |%s���K |%s�[�ċz |%s�������K�� |\nEnemy\nHP: %f\n",
            player.name,
            player.intelligence,
            player.pos[0],
            player.pos[1],
            cursor.pos,
            state,
            (int)player.hp,
            player.intelligence,
            player.item[0],
            player.item[1],
            player.item[2],
            cursor.pos == 0 ? ">" : " ",
            cursor.pos == 1 ? ">" : " ",
            cursor.pos == 2 ? ">" : " ",
            cursor.pos == 3 ? ">" : " ",
            cursor.pos == 0 ? ">" : " ",
            cursor.pos == 1 ? ">" : " ",
            cursor.pos == 2 ? ">" : " ",
            cursor.pos == 3 ? ">" : " ",
            enemies[player.pos[0] != 7 ? player.pos[0] : player.pos[1] == 2 ? 7 : 8].hp
        );
    }
    return 0;
}