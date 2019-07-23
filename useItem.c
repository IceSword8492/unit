// Author: 吉岡誇太郎

void useItem (int a)
{
    if (a == 0)
    {
          if (player.item[0] > 0)
          {
            player.hp = player.maxHp;
            player.item[0] -= 1;
          }
    }
    if (a == 1)
    {
          if (player.item[1] > 0)
          {
              player.item[1] -= 1;
          }
    }
    if (a == 2)
    {
        if (player.item[2] > 0)
        {
            player.item[2] -= 1;
        }
    }
}