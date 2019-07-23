// Author: 中村宥哉
// 購買関連の定義

#ifndef SHOPDEF
#define SHOPDEF

typedef struct Shop {
    int prices[3];
    int amount[3];
} Shop;

Shop new_Shop (int p1, int p2, int p3, int a1, int a2, int a3)
{
    Shop s = {
        {p1, p2, p3},
        {a1, a2, a3}
    };
    return s;
}

void buy (int id)
{
    if (player.money >= shops[player.getGradeId()].prices[id])
    {
        player.money -= shops[player.getGradeId()].prices[id];
        player.item[id] += (id == 1 ? 5 : 1);
        shops[player.getGradeId()].amount[id]--;
    }
}

#endif