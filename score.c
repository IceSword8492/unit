//åF‡VóSäÛ
//ÉXÉRÉAéZèo

#ifndef SCORE
#define SCORE

int getScore ()
{
    if (debug)
    {
        return 0;
        // return 10000 / 660 * (calcRemain() / 1000) + 1500 / 4000 * player.money + 5000; // #DEBUG
    }
    else if (trueClear)
    {
        return 10000 / 660 * (calcRemain() / 1000) + 1500 / 4000 * player.money + 5000;
    }
    else if (win)
    {
        return 10000 / 660 * (calcRemain() / 1000) + 1500 / 4000 * player.money;
    }
    else if (lose)
    {
        return 0;
    }
    else
    {

        return 0;
    }
}

#endif