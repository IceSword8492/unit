#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

float CRITICAL = 1.5f;

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
    struct Enemy* self; // 自身
    float hp;             // HP
    float maxHp;          // 最大HP
    float stdAtk;       // 基礎攻撃力
    bool charge;        // 溜めの有無
    int dmgCut;         // 半減の残りターン数
    int intelligence;   // もらえる知識量
    int type;           // 中:1, 通常:2, 裏ボス:3か雑魚:0か
    int act;            // 行動ルーチン
    int spact;          // 特殊行動
    int state[256];     // 特殊行動用配列
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
        spact,
        {0}
    };
    return e;
}

Enemy enemies[9]; 

#define SKILL_F1B 1
#define SKILL_F2B 2
#define SKILL_F3B 3
#define SKILL_F4B 4
#define ROUTINE_F4B 1
#define SKILL_LAST 5
#define ROUTINE_LAST 2
//敵の初期化by吉岡誇太郎
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
bool acttmp; // spactを実行したのちにactも実行する場合はtrueにする

Enemy* getEnemy ()
{
    return &enemies[player.pos[0] != 7 ? player.pos[0] : player.pos[1] == 2 ? 7 : 8];
}

typedef struct Spact {
    float (*spact)();
} Spact;

float spact_1b ()
{
    if (getEnemy()->hp <= getEnemy()->maxHp / 2)
    {
        return 1.5*getEnemy()->stdAtk;
    }
    return getEnemy()->stdAtk;
}

float spact_2b ()
{
    if(getEnemy()->hp <= getEnemy()->maxHp / 4)
    {
        tmpAttack *= 1.5;
    }
    if(getEnemy()->hp <= getEnemy()->maxHp / 10)
    {
        getEnemy()->hp  += getEnemy()->maxHp / 5;
    }
    
    return 0;
}

float spact_3b ()
{
    if(getEnemy()->hp <= getEnemy()->maxHp / 4)
    {
        getEnemy()->dmgCut = 1 ;
    }

    if(getEnemy()->hp <= 3000)
    {
        return getEnemy()->stdAtk * 2;
    }

    return 0;
}

float spact_4b ()
{
    if (getEnemy()->hp <= getEnemy()->maxHp / 2 && getEnemy()->state[0] == 0)
    {
        player.hp -= (player.hp/100)*99;
        getEnemy()->state[0] = 1;
        return 0;
    }
        

    if (getEnemy()->hp <= getEnemy()->maxHp / 5)
    {
        getEnemy()->hp = getEnemy()->maxHp / 2;
        return 0;
    }
    acttmp = true;
    return 0;
}

float spact_last ()
{
    if (getEnemy()->hp <= getEnemy()->maxHp / 5)
    {
        getEnemy()->dmgCut = 1;
    }
    acttmp = true;
    return 0;
}

Spact spact[] = {
    
    {spact_1b},
    {spact_2b},
    {spact_3b},
    {spact_4b},
    {spact_last}
};

int turn; // 現在のターン数を保持

typedef struct Act {
    float (*act)();
} Act;

float act_4b ()
{
    switch (turn % 4)
    {
    case 1:
        getEnemy()->charge = true;
        return 0;
    default:
        return getEnemy()->stdAtk;
    }
}

float act_last ()
{
    switch (turn % 5)
    {
    case 1:
        getEnemy()->dmgCut = 2;
        return 0;
    case 2:
        getEnemy()->charge = true;
        return 0;
    default:
        return getEnemy()->stdAtk;
    }
}

Act act[] = {
    {act_4b},
    {act_last}
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

void updateSkillsRecastTurn ()
{
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
}

void battleBegin ()
{
    turn = 0;
    setState(D_BATTLE);
    setCursor(0);
    if (getEnemy()->type == 3)
    {
        if (!player.item[2])
        {
            player.hp = 0; // 先制攻撃
        }
    }
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
            damage(NORMAL_ATTACK);
            attack();
            enemyAction();
            updateSkillsRecastTurn();
            turn++;
            break;
        case 1:
            if (player.item[1])
            {
                player.item[1]--;
                damage(REPORT_ATTACK);
                attack();
                enemyAction();
                updateSkillsRecastTurn();
                turn++;
            }
            break;
        case 2:
            setState(D_SKILL);
            setCursor(0);
            break;
        }
        

        break;
    case D_SKILL:
        if (!cursor.pos)
        {
            setState(D_BATTLE);
            setCursor(2);
        }
        else if (player.pos[0] == 7 && player.pos[1] == 3 && !player.recast[cursor.pos - 1])
        {
            if (cursor.pos <= 4)
            {
                useSkill();
                setState(D_BATTLE);
                enemyAction();
                updateSkillsRecastTurn();
                turn++;
                setCursor(0);
            }
        }
        else if (cursor.pos <= player.pos[0] / 2 + 1 && !player.recast[cursor.pos - 1])
        {
            useSkill();
            setState(D_BATTLE);
            enemyAction();
            updateSkillsRecastTurn();
            turn++;
            setCursor(0);
        }
        break;
    }
}

int main (int argc, const char** argv)
{
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-noCritical") == 0)
        {
            CRITICAL = 1.0f;
        }
    }
    win = false;
    lose = false;
    trueClear = false;
    cursor.pos = 0;
    player = new_Student("TestStudent");
    player.intelligence = 300;
    player.item[0] = 2;
    player.item[1] = 100;
    player.item[2] = 1;
    player.pos[0] = 7;
    player.pos[1] = 3;
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
                initializeEnemies();
                break;
            case 'a':
                if (cursor.pos > 0) 
                {
                    cursor.pos--;
                    initializeEnemies();
                }
                break;
            case 'w':
                player.pos[0]++;
                initializeEnemies();
                break;
            case 's':
                player.pos[0]--;
                initializeEnemies();
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
            case 'p':
                battleBegin();
                break;
            }
        }
        printf("---\n名前: %s\n知識: %d\npos[0]: %d, pos[1]: %d\nCursor: %d\nstate: %d\nHP: %5d, 知識: %4d\nエナジードリンク: %2d本, レポート用紙: %3d枚, 履歴書: %1d枚\nRecast: %d %d %d %d\nTurn: %d\n|%s|%s出席 |%sレポート提出 |%sスキル |%sアイテム |\n|%s|%s戻る |%s予\習 |%s復習 |%s深呼吸 |%s研究室訪問 |\nEnemy\nHP: %f\n",
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
            player.recast[0],
            player.recast[1],
            player.recast[2],
            player.recast[3],
            turn,
            state == 2 ? "*" : " ",
            cursor.pos == 0 ? ">" : " ",
            cursor.pos == 1 ? ">" : " ",
            cursor.pos == 2 ? ">" : " ",
            cursor.pos == 3 ? ">" : " ",
            state == 4 ? "*" : " ",
            cursor.pos == 0 ? ">" : " ",
            cursor.pos == 1 ? ">" : " ",
            cursor.pos == 2 ? ">" : " ",
            cursor.pos == 3 ? ">" : " ",
            cursor.pos == 4 ? ">" : " ",
            getEnemy()->hp
        );
    }
    return 0;
}