//吉岡誇太郎
//戦闘の勝利処理
void battleVictory ()
{
    Enemy enemy = enemies[player.pos[0] != 7 ? player.pos[0] : player.pos[1] == 2 ? 7 : 8];
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