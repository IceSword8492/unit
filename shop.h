// Author: ’†‘º—GÆ
// w”ƒŠÖ˜A‚Ì’è‹`

#ifndef SHOPDEF
#define SHOPDEF

typedef struct Shop {
    struct Shop* self;
    int prices[3];
    int amount[3];
} Shop;

Shop new_Shop (int p[3], int a[3])
{
    Shop s = {
        &s,
        p,
        a
    };
    return s;
}

#endif