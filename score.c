//åF‡VóSäÛ
//ÉXÉRÉAéZèo

#ifndef SCORE
#define SCORE

void getScore ()
{
    if (debug)
    {
        score = 0;
    }
    else if (trueClear)
    {
        score = 10000 / 660 * (calcRemain() / 1000) + 1500 / 4000 * player.money + 5000;
    }
    else
    {
        score = 10000 / 660 * (calcRemain() / 1000) + 1500 / 4000 * player.money;
    }
}

#endif