//吉岡�?太�?
//戦闘�?�勝利処�?
void battleVictory ()
{
    Enemy enemy = *getEnemy();
    addIntelligence(enemy.intelligence);
    setState(D_DUNGEON);
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