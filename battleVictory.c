//吉岡誇太郎
//戦闘の勝利処理
void battleVictory ()
{
    Enemy enemy = *getEnemy();
    addIntelligence(enemy.intelligence);
    if(enemy.type == 1)
    {
        player.pos[0]++;
    }
    if(enemy.type == 3)
    {
        win = true;
        trueClear=true; 
    }
}