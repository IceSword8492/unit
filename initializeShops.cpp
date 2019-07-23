// Author: 中村宥哉
// shops変数初期化

#ifndef INITIALIZESHOPS
#define INITIALIZESHOPS

void initializeShops ()
{
    Shop s[4] = {
        new_Shop(500, 100, 1000, 9999, 9999, 0),
        new_Shop(500, 100, 1000, 9999, 9999, 0),
        new_Shop(500, 100, 1000, 9999, 9999, 0),
        new_Shop(500, 100, 1000, 9999, 9999, 1)
    };
    memcpy(shops, s, sizeof(s));
}

#endif