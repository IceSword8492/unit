//åF‡VóSäÛ
//ÉXÉRÉAéZèo

#ifndef SCORE
#define SCORE

void Score ()
{
    if(trueClear)
    {
        score = calcRemain() / 1000 + player.money + 500;
    }
    else
    {
        score = calcRemain() / 1000 + player.money;
    }
}

#endif