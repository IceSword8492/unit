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
            attack();
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
        }
    case D_SKILL:
        if (!cursor.pos)
        {
            setState(D_BATTLE);
            setCursor(2);
        }
        else if (player.pos[0] == 7 && player.pos[1] == 3 && !player.recast[cursor.pos - 1])
        {
            if (cursor.pos <= 4)
            {
                useSkill();
                setState(D_BATTLE);
                enemyAction();
                updateSkillsRecastTurn();
                turn++;
                setCursor(0);
            }
        }
        else if (cursor.pos <= player.pos[0] / 2 + 1 && !player.recast[cursor.pos - 1])
        {
            useSkill();
            setState(D_BATTLE);
            enemyAction();
            updateSkillsRecastTurn();
            turn++;
            setCursor(0);
        }
        break;        

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