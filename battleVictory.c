//吉岡�?太�?
//戦闘�?�勝利処�?
void battleVictory ()
{
    Enemy enemy = *getEnemy();
    addIntelligence(enemy.intelligence);
    setState(D_DUNGEON);
    player.recast[0] = 0;
    player.recast[1] = 0;
    player.recast[2] = 0;
    player.recast[3] = 0;
    if(enemy.type == 1)
    {
        player.pos[0]++;
        player.money += 1000;
    }
    if(enemy.type == 3)
    {
        win = true;
        trueClear=true; 
    }
}