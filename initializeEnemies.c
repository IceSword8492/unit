// fixed by Yuya Nakamura
// added #ifndef~#endif
// replaced NULL to 0
// bug fixed

#ifndef INITENEMIES
#define INITENEMIES

#define SKILL_F1B 1
#define SKILL_F2B 2
#define SKILL_F3B 3
#define SKILL_F4B 4
#define ROUTINE_F4B 5
#define SKILL_LAST 6
#define ROUTINE_LAST 7
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

#endif