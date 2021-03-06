// Author: ºGÆ
// Define enemy struct and constructor

#ifndef ENEMY
#define ENEMY

typedef struct Enemy
{
    float hp;             // HP
    float maxHp;          // ÅåHP
    float stdAtk;       // îbUÍ
    bool charge;        // ­ßÌL³
    int dmgCut;         // ¼¸Ìcè^[
    int intelligence;   // àç¦ém¯Ê
    int type;           // :1, Êí:2,  {X:3©G:0©
    int act;            // s®[`
    int spact;          // Áês®
    int state[256];     // 0 -> ª«
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