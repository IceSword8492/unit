// Author: 中村宥哉
// Define enemy struct and constructor

#ifndef ENEMY
#define ENEMY

typedef struct Enemy
{
    float hp;             // HP
    float maxHp;          // 最大HP
    float stdAtk;       // 基礎攻撃力
    bool charge;        // 溜めの有無
    int dmgCut;         // 半減の残りターン数
    int intelligence;   // もらえる知識量
    int type;           // 中:1, 通常:2, 裏ボス:3か雑魚:0か
    int act;            // 行動ルーチン
    int spact;          // 特殊行動
    int state[256];     // 0 -> 根性
} Enemy;

Enemy new_Enemy (float hp, float maxHp, float stdAtk, int intelligence, int type, int act, int spact)
{
    Enemy e = {
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

#endif