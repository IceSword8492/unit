// Author: ’†‘º—GÆ
// w”ƒŠÖ˜A‚Ì’è‹`

#ifndef SHOPDEF
#define SHOPDEF

typedef struct Shop {
    struct Shop* self;
    int prices[3];
    int amount[3];
} Shop;

Shop new_Shop (int p1, int p2, int p3, int a1, int a2, int a3)
{
    Shop s = {
        &s,
        {p1, p2, p3},
        {a1, a2, a3}
    };
    return s;
}

#endif