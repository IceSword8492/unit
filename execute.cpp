// Author:中村宥哉
// 決定キー押下時実行関数の定義

#ifndef EXECUTE
#define EXECUTE

void execute ()
{
    switch (state)
    {
    case D_BATTLE:
        isCritical();
        switch (cursor.pos)
        {
        case 0:
            damage(NORMAL_ATTACK);
            if (attack())
            {
                break;
            }
            enemyAction();
            updateSkillsRecastTurn();
            turn++;
            break;
        case 1:
            if (player.item[1])
            {
                player.item[1]--;
                damage(REPORT_ATTACK);
                attack();
                enemyAction();
                updateSkillsRecastTurn();
                turn++;
            }
            break;
        case 2:
            setState(D_SKILL);
            setCursor(0);
            break;
        case 3: // use item
            if (player.item[0] > 0)
            {
                useItem(0);
                enemyAction();
                updateSkillsRecastTurn();
                turn++;
            }
            break;
        }
        break;
    case D_SKILL:
        if (!cursor.pos)
        {
            setState(D_BATTLE);
            setCursor(2);
        }
        else if (player.pos[0] == 7 && player.pos[1] == 3 && !player.recast[cursor.pos - 1])
        {
            useSkill(cursor.pos - 1);
            setState(D_BATTLE);
            enemyAction();
            updateSkillsRecastTurn();
            turn++;
            setCursor(0);
        }
        else if (!player.recast[cursor.pos - 1])
        {
            useSkill(cursor.pos - 1);
            setState(D_BATTLE);
            enemyAction();
            updateSkillsRecastTurn();
            turn++;
            setCursor(0);
        }
        break;
    case D_SHOP:
        switch (cursor.pos)
        {
        case 0:
            setState(D_DUNGEON);
            break;
        case 1:
        case 2:
        case 3:
            buy(cursor.pos - 1);
            break;
        }
        break;
    case D_ESC_MENU:
        switch (cursor.pos)
        {
        case 0:
            setState(prevState);
            break;
        case 1:
            safeExit(0);
            break;
        }
        break;
    }
}

#endif